//
//  view.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef view_h
#define view_h

#include <view_interface.h>

namespace lett{
class ViewBridge{
    NSView        *m_ns_view;
public:
    ~ViewBridge();
    ViewBridge();
    ViewBridge(const ViewBridge&) = delete;
    ViewBridge(ViewBridge&&) = delete;
    
    void SetView(NSView*);
    NSView *GetView();
};
}

#endif
