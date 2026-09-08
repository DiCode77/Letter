//
//  application.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef application_hpp
#define application_hpp

#include <unordered_map>
#include <functional>

namespace lett {

class AppStorage{
public:
    using Func = std::function<bool()>;
private:
    std::unordered_map<void*, Func> m_um_func;
public:
    AppStorage() = default;
    AppStorage(const AppStorage&) = delete;
    AppStorage(AppStorage&&) = delete;
    
    void AddFunc(void*, Func);
    Func GetFunc(void*);
    bool IsEmpty(void*) const;
    bool RemoveFunc(void*);
};

class AppBridge;
class App{
    AppBridge *m_app_bridge;
    AppStorage m_storage;
public:
    ~App();
    App();
    App(const App&) = delete;
    void Run();
    void Terminate();
    void Stop();
    void *GetApp();
    AppStorage &GetAppStorage();
};
};
#endif
