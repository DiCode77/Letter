#include <application_bridge.h>

lett::AppBridge::~AppBridge(){
    [this->m_ns_app setDelegate:nil];
    
    [this->m_app_interface release];
    this->m_app_interface = nil;
}

lett::AppBridge::AppBridge(lett::App *p_app) : m_ns_app([NSApplication sharedApplication]), m_app_interface([[AppInterface alloc] init]){
    [this->m_app_interface setM_oem_app:p_app];
    [this->m_ns_app setDelegate:this->m_app_interface];
}

NSApplication *lett::AppBridge::GetApp(){
    return this->m_ns_app;
}

AppInterface *lett::AppBridge::GetAppInterface(){
    if (this->m_app_interface == nil){
        return nullptr;
    }
    return this->m_app_interface;
}
