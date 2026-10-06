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
class Object;
class DataSet;
}

@interface WindowInterface : NSObject <NSWindowDelegate>
// Actually, it's not really necessary right now, but it will be needed as the project progresses.
@property (nonatomic, assign) lett::Object  *m_oem_object;
@property (nonatomic, assign) lett::DataSet *m_data_set;
@end

#endif
