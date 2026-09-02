//
//  window.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef window_h
#define window_h

#include <window_interface.h>

namespace lett{
class WindowBridge{
    NSWindow        *m_ns_window;
    WindowInterface *m_interface;
public:
    ~WindowBridge();
    WindowBridge();
    
    void SetWindow(NSWindow*, Create<lett::window>*);
    NSWindow *GetWindow();
};
}

#endif
