//
//  application.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef application_hpp
#define application_hpp

#include <algorithm>
#include <ranges>

#include <app_storage.hpp>

namespace lett{

class AppBridge;
class App{
    AppBridge       *m_app_bridge;
    lett::AppStorage m_quantity;
    bool             m_is_close = true;
public:
    virtual ~App();
    
    App();
    App(const App&) = delete;
    App(App&&) = delete;
    
    void Run();
    void Terminate();
    void Stop();      // Stops the event loop without releasing resources.
    void Finish();
    void *GetNSApp(); // NSApplication*
    void DestroyObject(const lett::UniqueId&);
    lett::AppStorage &GetAppQuantity();
    void PreventAppFromClosing(bool);
    bool GetIsClosing() const;
};
};
#endif
