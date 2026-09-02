//
//  window.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef window_h
#define window_h

#include <Cocoa/Cocoa.h>

namespace lett{
class WindowBridge{
    NSWindow *m_ns_window;
public:
    WindowBridge() : m_ns_window(nil){}
    
    void SetWindow(NSWindow *window){
        if (this->m_ns_window == nil){
            this->m_ns_window = window;
        }
    }
    
    NSWindow *GetWindow(){
        return this->m_ns_window;
    }
};
}

#endif
