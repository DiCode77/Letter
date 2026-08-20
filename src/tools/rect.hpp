//
//  rect.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef rect_hpp
#define rect_hpp

#include <placement.hpp>

namespace lett{

class  point;
class  size;

template <typename Templ>
class Rect : public lett::Placement<Rect<Templ>>{
    struct Strorage{
        size_t x = 0;
        size_t y = 0;
    } stg;
public:
    Rect() = default;
    Rect(const size_t&, const size_t&);
    Rect(const Templ&);
    
    void SetValue(const size_t&, const size_t&) override;
    void SetValue(const Rect&) override;
    
    size_t GetX() const override;
    size_t GetY() const override;
    
    bool operator== (const Rect&) const override;
    bool operator!= (const Rect&) const override;
    
    Rect operator+ (const Rect&) override;
    Rect operator- (const Rect&) override;
};


#include <rect.inl>
}
#endif
