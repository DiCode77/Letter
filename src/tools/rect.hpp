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

namespace lett{

class  point;
class  size;

template <typename Templ>
class Rect : public lett::RectPlacement<Rect<Templ>>{
    struct Strorage{
        lett::val_t x = 0;
        lett::val_t y = 0;
    } stg;
public:
    Rect() = default;
    Rect(const lett::val_t&, const lett::val_t&);
    Rect(const Templ&);
    
    void SetValue(const lett::val_t&, const lett::val_t&) override;
    void SetValue(const Rect&) override;
    
    lett::val_t GetX() const override;
    lett::val_t GetY() const override;
    
    bool operator== (const Rect&) const override;
    bool operator!= (const Rect&) const override;
    
    Rect operator+ (const Rect&) override;
    Rect operator- (const Rect&) override;
    
    Rect &operator= (const Rect&) override;
    Rect &operator+= (const Rect&) override;
    Rect &operator-= (const Rect&) override;
};


#include <rect.inl>
}
#endif
