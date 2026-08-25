#include <application.hpp>
#include <application.h>

lett::App::~App(){}
lett::App::App(){
    this->m_app = reinterpret_cast<NSApplication*>([NSApplication sharedApplication]);
}

void lett::App::run(){
    [reinterpret_cast<NSApplication*>(this->m_app) run];
}

void lett::App::terminate(){
    [reinterpret_cast<NSApplication*>(this->m_app) terminate:nil];
}

void lett::App::stop(){
    [reinterpret_cast<NSApplication*>(this->m_app) stop:nil];
}

void *lett::App::GetApp(){
    return this->m_app;
}
