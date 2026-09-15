#include <application.hpp>
#include <application_bridge.h>

@implementation AppInterface

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_oem_app = nil;
    }
    
    return self;
}

- (void)dealloc{
    [super dealloc];
}

- (void)DestroyTheTarget:(const lett::UniqueId&)is_id{
    if (!self.m_oem_app->GetAppQuantity().Empty()){
        if (lett::Object *obj = self.m_oem_app->GetAppQuantity().GetObject(is_id); obj != nullptr){
            delete obj;
            
            self.m_oem_app->GetAppQuantity().RemoveObject(is_id);
            
            NSApplication *app = reinterpret_cast<NSApplication*>(self.m_oem_app->GetNSApp());
            [app terminate:nil];
        }
    }
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender{
    if (!self.m_oem_app->GetAppQuantity().Empty()){
        return NSTerminateCancel;
    }
    
    if ([[sender windows] count] != 0){
        return NSTerminateCancel;
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

lett::AppStorage &lett::App::GetAppQuantity(){
    return this->m_quantity;
}
