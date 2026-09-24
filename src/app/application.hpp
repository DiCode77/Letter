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
    bool m_prevent_main_loop_stop;
public:
    virtual ~App();
    
    App();
    App(const App&) = delete;
    App(App&&) = delete;
    
    void Run();       // Launch the app.
    
    // This method triggers the Terminate event and calls the applicationShouldTerminate delegate, which causes the Finish() method to execute, thereby terminating the program.
    void Terminate();
    
    void Stop();      // Stops the event loop without releasing resources.
    void Finish();    // This will automatically close all windows in the program.
    void *GetNSApp(); // NSApplication*
    void DestroyObject(const lett::UniqueId&); // Completely deletes the object; you just need to specify its ID.
    
    // Returns a map containing all registered objects; you should not use this, as incorrect usage may cause issues with object lifecycle management
    lett::AppStorage &GetAppStorageQuantity();
    
    void SetMainLoopStatus(bool);
    bool GetMainLoopStatus() const;
};
};
#endif
