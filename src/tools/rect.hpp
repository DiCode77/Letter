//
//  rect.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef rect_hpp
#define rect_hpp

#include <settings.hpp>
#include <placement.hpp>
#include <concepts>

namespace lett{

class  point;
class  size;

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
class Rect : public lett::RectPlacement<Rect<Templ>>{
    lett::val_t x = 0;
    lett::val_t y = 0;
public:
    Rect() = default;
    Rect(const lett::val_t&, const lett::val_t&);
    Rect(const Rect&);
    
    void SetValue(const lett::val_t&, const lett::val_t&) override;
    void SetValue(const Rect&) override;
    
    const lett::val_t &GetX() override;
    const lett::val_t &GetY() override;
    const lett::val_t &GetX() const override;
    const lett::val_t &GetY() const override;
    
    bool operator== (const Rect&) const override;
    bool operator!= (const Rect&) const override;
    
    Rect operator+ (const Rect&) override;
    Rect operator- (const Rect&) override;
    
    Rect &operator= (const Rect&) override;
    Rect &operator+= (const Rect&) override;
    Rect &operator-= (const Rect&) override;
};

const Rect<point> default_point = {-1, -1};
const Rect<size>  default_size  = {-1, -1};

#include <rect.inl>
}
#endif
