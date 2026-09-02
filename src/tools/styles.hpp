//
//  styles.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef styles_hpp
#define styles_hpp

namespace lett{
namespace style{

enum class window : int{
    MaskBorderless             = 0,
    MaskTitled                 = 1 << 0,
    MaskClosable               = 1 << 1,
    MaskMiniaturizable         = 1 << 2,
    MaskResizable              = 1 << 3,
    MaskTexturedBackground     = 1 << 8,
    MaskUnifiedTitleAndToolbar = 1 << 12,
    MaskFullScreen             = 1 << 14,
    MaskFullSizeContentView    = 1 << 15,
    MaskUtilityWindow          = 1 << 4,
    MaskDocModalWindow         = 1 << 6,
    MaskNonactivatingPanel     = 1 << 7,
    MaskHUDWindow              = 1 << 13
};

constexpr window operator| (window lval, window rval){
    int val = int(lval) | int(rval);
    return (window)val;
}

}
}

#endif
