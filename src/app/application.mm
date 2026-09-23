#include <application.hpp>
#include <application_bridge.h>

@implementation AppInterface

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_oem_app             = nil;
        _m_classic_closure_app = false;
    }
    
    return self;
}

- (void)dealloc{
    [super dealloc];
}

- (void)DestroyTheTarget:(const lett::UniqueId&)is_id{
    if (!self.m_oem_app->GetAppStorageQuantity().Empty()){
        if (lett::Object *obj = self.m_oem_app->GetAppStorageQuantity().GetObject(is_id); obj != nullptr){
            delete obj;
            
            self.m_oem_app->GetAppStorageQuantity().RemoveObject(is_id);
            
            self.m_classic_closure_app = true;
            
            NSApplication *app = reinterpret_cast<NSApplication*>(self.m_oem_app->GetNSApp());
            [app terminate:nil];
        }
    }
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender{
    if (!self.m_oem_app->GetAppStorageQuantity().Empty() && self.m_classic_closure_app == true){
        self.m_classic_closure_app = false;
        
        return NSTerminateCancel;
    }
    
    // As for this block of code, it works as intended, but I'm leaving this comment so that we can explore alternatives in the future.
    if (self.m_classic_closure_app == false){
        auto &um_list = self.m_oem_app->GetAppStorageQuantity().GetUMapObjectList();
        for (auto &obj : um_list | std::views::values){
            delete obj;
        }
        um_list.clear();
    }
    
    return NSTerminateNow;
}

- (void)applicationWillTerminate:(NSNotification *)notification{
    delete self.m_oem_app;
}

@end

lett::App::~App(){
    delete this->m_app_bridge;
}

lett::App::App() : m_app_bridge(new AppBridge(this)){}

void lett::App::Run(){
    [this->m_app_bridge->GetApp() run];
}

void lett::App::Terminate(){
    [this->m_app_bridge->GetApp() terminate:nil];
}

void lett::App::Stop(){
    [this->m_app_bridge->GetApp() stop:nil];
}

void lett::App::Finish(){}

void *lett::App::GetNSApp(){
   return reinterpret_cast<void*>(this->m_app_bridge->GetApp());
}

void lett::App::DestroyObject(const lett::UniqueId &is_id){
    [this->m_app_bridge->GetAppInterface() DestroyTheTarget:is_id];
}

lett::AppStorage &lett::App::GetAppStorageQuantity(){
    return this->m_quantity;
}
