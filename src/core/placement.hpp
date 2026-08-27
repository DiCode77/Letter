//
//  placement.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef placement_hpp
#define placement_hpp

#include <settings.hpp>

namespace lett{

template <typename Te>
class RectPlacement{
public:
    virtual ~RectPlacement() = default;
    virtual void SetValue(const lett::val_t&, const lett::val_t&) = 0;
    virtual void SetValue(const Te&) = 0;
    virtual lett::val_t GetX() const = 0;
    virtual lett::val_t GetY() const = 0;
    
    virtual bool operator== (const Te&) const = 0;
    virtual bool operator!= (const Te&) const = 0;
    
    virtual Te operator+ (const Te&) = 0;
    virtual Te operator- (const Te&) = 0;
    
    virtual Te &operator= (const Te&)  = 0;
    virtual Te &operator+= (const Te&) = 0;
    virtual Te &operator-= (const Te&)  = 0;
};
}

#endif
