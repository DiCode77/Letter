//
//  application.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef application_hpp
#define application_hpp

namespace lett {
class App{
    void *m_app;
public:
    ~App();
    App();
    App(const App&) = delete;
    void run();
    void terminate();
    void stop();
    void *GetApp();
};
};
#endif
