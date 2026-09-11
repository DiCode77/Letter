#include <application.hpp>
#include <application.h>

@implementation AppInterface

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_oem_app = nil;
    }
    
    return self;
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender{
    if (self.m_oem_app->GetWindowQuantity() > 0){
        return NSTerminateCancel;
    }
    
    return NSTerminateNow;
}

- (void)applicationWillTerminate:(NSNotification *)notification{
    delete self.m_oem_app;
}

@end

void lett::AppStorage::AddFunc(void *is_id, Func func){
    this->m_um_func.insert(std::make_pair(is_id, std::move(func)));
}

lett::AppStorage::Func lett::AppStorage::GetFunc(void *is_id){
    if (auto it = this->m_um_func.find(is_id); it != this->m_um_func.end()){
        return it->second;
    }
    return {};
}

bool lett::AppStorage::IsEmpty(void *is_id) const{
    auto it = this->m_um_func.find(is_id);
    return it != this->m_um_func.end() ? true : false;
}

bool lett::AppStorage::RemoveFunc(void *is_id){
    if (auto it = this->m_um_func.find(is_id); it != this->m_um_func.end()){
        this->m_um_func.erase(it);
        return true;
    }
    return false;
}

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

void lett::App::Finish(){
    
}

void *lett::App::GetApp(){
   return reinterpret_cast<void*>(this->m_app_bridge->GetApp());
}

long lett::App::GetWindowQuantity(){
    return this->m_window_quantity;
}

void lett::App::IncreaseQuantity(){
    this->m_window_quantity++;
}

void lett::App::DecreaseQuantity(){
    if (this->m_window_quantity > 0)
        this->m_window_quantity--;
}

lett::AppStorage &lett::App::GetAppStorage(){
    return this->m_storage;
}
