#include <application.hpp>
#include <application.h>

lett::App::~App(){}
lett::App::App(){
    this->m_app = reinterpret_cast<NSApplication*>([NSApplication sharedApplication]);
}

void lett::App::Run(){
    [reinterpret_cast<NSApplication*>(this->m_app) run];
}

void lett::App::Terminate(){
    [reinterpret_cast<NSApplication*>(this->m_app) terminate:nil];
}

void lett::App::Stop(){
    [reinterpret_cast<NSApplication*>(this->m_app) stop:nil];
}

void *lett::App::GetApp(){
    return this->m_app;
}
