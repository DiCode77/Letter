//
//  window_interface.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef window_interface_h
#define window_interface_h

#include <Cocoa/Cocoa.h>

namespace lett{
template <typename>
class Create;
class window;
}

@interface WindowInterface : NSObject <NSWindowDelegate>
@property (nonatomic, assign) lett::Create<lett::window> *m_oem_window;
@end

#endif
