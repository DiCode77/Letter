#include <rect.hpp>

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect(const lett::val_t &x, const lett::val_t &y) : stg(x, y){}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect(const Templ &lobj) : Rect<Templ>::Rect(lobj.stg.x, lobj.stg.y){}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
void Rect<Templ>::SetValue(const lett::val_t &x, const lett::val_t &y){
    this->stg = {x, y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
void Rect<Templ>::SetValue(const Rect &val){
    this->stg = {val.stg.x, val.stg.y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
lett::val_t Rect<Templ>::GetX() const{
    return this->stg.x;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
lett::val_t Rect<Templ>::GetY() const{
    return this->stg.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
bool Rect<Templ>::operator== (const Rect<Templ> &obj) const{
    return this->stg.x == obj.stg.x && this->stg.y == obj.stg.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
bool Rect<Templ>::operator!= (const Rect<Templ> &obj) const{
    return this->stg.x != obj.stg.x || this->stg.y != obj.stg.y;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect Rect<Templ>::operator+ (const Rect &obj){
    return {this->stg.x + obj.stg.x, this->stg.y + obj.stg.y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect Rect<Templ>::operator- (const Rect &obj){
    return {this->stg.x - obj.stg.x, this->stg.y - obj.stg.y};
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator= (const Rect &obj){
    this->stg = obj.stg;
    return *this;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator+= (const Rect &obj){
    this->stg = { this->stg.x + obj.stg.x, this->stg.y + obj.stg.y };
    return *this;
}

template <typename Templ> requires (std::same_as<Templ, point> || std::same_as<Templ, size>)
Rect<Templ>::Rect &Rect<Templ>::operator-= (const Rect &obj){
    this->stg = { this->stg.x - obj.stg.x, this->stg.y - obj.stg.y };
    return *this;
}
