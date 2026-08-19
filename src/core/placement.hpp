//
//  placement.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef placement_hpp
#define placement_hpp

namespace lett{
template <typename Te>
class Placement{
public:
    virtual ~Placement() = default;
    virtual void SetValue(const size_t&, const size_t&) = 0;
    virtual void SetValue(const Te&) = 0;
    virtual size_t GetX() = 0;
    virtual size_t GetY() = 0;
};
}

#endif
