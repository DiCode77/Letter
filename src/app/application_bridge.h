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
    ~AppBridge();
    AppBridge() = delete;
    AppBridge(const AppBridge&) = delete;
    AppBridge(AppBridge&&) = delete;
    AppBridge(lett::App*);
    
    NSApplication *GetApp();
    AppInterface  *GetAppInterface();
};
}


#endif
