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
    App           *m_app;
public:
    
    ~AppBridge(){}
    AppBridge(App *p_app) : m_app(p_app){}
    
    NSApplication *GetApp(){
        return this->m_ns_app;
    }
    
    void SetApp(NSApplication *p_app){
        this->m_ns_app = p_app;
    }
};
}


#endif
