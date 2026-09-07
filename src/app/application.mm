#include <application.hpp>
#include <application.h>

@implementation AppInterface
@end

lett::App::~App(){}

lett::App::App() : m_app_bridge(new AppBridge(this)){
    this->m_app_bridge->SetApp([NSApplication sharedApplication]);
}

void lett::App::Run(){
    [this->m_app_bridge->GetApp() run];
}

void lett::App::Terminate(){
    [NSApp terminate:nil];
}

void lett::App::Stop(){
    [this->m_app_bridge->GetApp() stop:nil];
}

void *lett::App::GetApp(){
   return reinterpret_cast<void*>(this->m_app_bridge->GetApp());
}
