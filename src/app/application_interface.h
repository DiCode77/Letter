//
//  application_interface.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef application_interface_h
#define application_interface_h

#include <Cocoa/Cocoa.h>

namespace lett{
class App;
}

@interface AppInterface : NSObject <NSApplicationDelegate>
@property (nonatomic, assign) lett::App *m_oem_app;
@end

#endif
