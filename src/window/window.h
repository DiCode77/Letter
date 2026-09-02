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
    ~WindowBridge();
    WindowBridge();
    
    void SetWindow(NSWindow*);
    NSWindow *GetWindow();
};
}

#endif
