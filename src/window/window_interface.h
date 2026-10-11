//
//  window_interface.h
//  Letter
//
//  Created by DiCode77.
//

#ifndef window_interface_h
#define window_interface_h

#include <Cocoa/Cocoa.h>
#include <unordered_map>

namespace lett{
class Object;
class DataSet;
}

@interface WindowInterface : NSObject <NSWindowDelegate>
// Actually, it's not really necessary right now, but it will be needed as the project progresses.
@property (nonatomic, assign) lett::Object  *m_oem_object;
@property (nonatomic, assign) lett::DataSet *m_data_set;
@end

struct StorageTargetAndAction{
    SEL selector = nil;
    id  target   = nil;
};

@interface ButtonDelegate : NSObject <NSWindowDelegate>
@property (nonatomic, assign) lett::DataSet *m_data_set;
@property (nonatomic, assign) std::unordered_map<NSButton*, StorageTargetAndAction> m_um_storage_button;
@end

#endif
