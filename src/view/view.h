//
//  view.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef view_h
#define view_h

#include <Cocoa/Cocoa.h>

namespace lett{
class ViewBridge{
    NSView *m_ns_view;
public:
    ~ViewBridge();
    ViewBridge();
    
    void SetView(NSView*);
    NSView *GetView();
};
}

#endif
