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
    ViewBridge() : m_ns_view(nil){}
    
    void SetNSView(NSView *view){
        if (this->m_ns_view == nil){
            this->m_ns_view = view;
        }
    }
    
    NSView *GetNSView(){
        return this->m_ns_view;
    }
};
}

#endif
