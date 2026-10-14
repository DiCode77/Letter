#include <rect.hpp>

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect(const lett::val_t &_x, const lett::val_t &_y) : x(_x), y(_y){}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect(const Rect &lobj) : Rect<Templ>::Rect(lobj.x, lobj.y){}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
void Rect<Templ>::SetValue(const lett::val_t &_x, const lett::val_t &_y){
    this->x = _x;
    this->y = _y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
void Rect<Templ>::SetValue(const Rect &val){
    this->x = val.x;
    this->y = val.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
const lett::val_t &Rect<Templ>::GetX(){
    return this->x;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
const lett::val_t &Rect<Templ>::GetY(){
    return this->y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
const lett::val_t &Rect<Templ>::GetX() const{
    return this->x;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
const lett::val_t &Rect<Templ>::GetY() const{
    return this->y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
bool Rect<Templ>::operator== (const Rect<Templ> &obj) const{
    return this->x == obj.x && this->y == obj.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
bool Rect<Templ>::operator!= (const Rect<Templ> &obj) const{
    return this->x != obj.x || this->y != obj.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect Rect<Templ>::operator+ (const Rect &obj){
    return {this->x + obj.x, this->y + obj.y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect Rect<Templ>::operator- (const Rect &obj){
    return {this->x - obj.x, this->y - obj.y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator= (const Rect &obj){
    this->SetValue(obj);
    return *this;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator+= (const Rect &obj){
    this->x += obj.x;
    this->y += obj.y;
    return *this;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator-= (const Rect &obj){
    this->x -= obj.x;
    this->y -= obj.y;
    return *this;
}
