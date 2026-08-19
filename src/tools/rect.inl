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
size_t Rect<Templ>::GetX(){
    return this->stg.x;
}

template <typename Templ>
size_t Rect<Templ>::GetY(){
    return this->stg.y;
}
