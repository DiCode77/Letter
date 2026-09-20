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
class UniqueId;
}

@interface AppInterface : NSObject <NSApplicationDelegate>
@property (nonatomic, assign) lett::App *m_oem_app;
@property (nonatomic, assign) bool       m_closed_app;

- (void)DestroyTheTarget:(const lett::UniqueId&)is_id;

@end

#endif
