//
//  application.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef application_h
#define application_h

#include <application_interface.h>

namespace lett{

class App;
class AppBridge{
    NSApplication *m_ns_app;
    AppInterface  *m_app_interface;
public:
    ~AppBridge(){
        [this->m_ns_app setDelegate:nil]; // ?
        
        [this->m_app_interface release];
        this->m_app_interface = nil;
    }
    
    AppBridge() = delete;
    AppBridge(const AppBridge&) = delete;
    AppBridge(AppBridge&&) = delete;
    
    AppBridge(lett::App *p_app) : m_ns_app([NSApplication sharedApplication]), m_app_interface([[AppInterface alloc] init]){
        [this->m_app_interface setM_oem_app:p_app];
        [this->m_ns_app setDelegate:this->m_app_interface];
    }
    
    NSApplication *GetApp(){
        return this->m_ns_app;
    }
};
}


#endif
