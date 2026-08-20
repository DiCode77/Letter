#include <rect.hpp>

template <typename Templ>
Rect<Templ>::Rect(const size_t &x, const size_t &y) : stg(x, y){}

template <typename Templ>
Rect<Templ>::Rect(const Templ &lobj) : Rect<Templ>::Rect(lobj.stg.x, lobj.stg.y){}

template <typename Templ>
void Rect<Templ>::SetValue(const size_t &x, const size_t &y){
    this->stg = {x, y};
}

template <typename Templ>
void Rect<Templ>::SetValue(const Rect &val){
    this->stg = {val.stg.x, val.stg.y};
}

template <typename Templ>
size_t Rect<Templ>::GetX() const{
    return this->stg.x;
}

template <typename Templ>
size_t Rect<Templ>::GetY() const{
    return this->stg.y;
}

template <typename Templ>
bool Rect<Templ>::operator== (const Rect<Templ> &obj) const{
    return this->stg.x == obj.stg.x && this->stg.y == obj.stg.y;
}

template <typename Templ>
bool Rect<Templ>::operator!= (const Rect<Templ> &obj) const{
    return this->stg.x != obj.stg.x || this->stg.y != obj.stg.y;
}

template <typename Templ>
Rect<Templ>::Rect Rect<Templ>::operator+ (const Rect &obj){
    return {this->stg.x + obj.stg.x, this->stg.y + obj.stg.y};
}

template <typename Templ>
Rect<Templ>::Rect Rect<Templ>::operator- (const Rect &obj){
    return {this->stg.x - obj.stg.x, this->stg.y - obj.stg.y};
}
