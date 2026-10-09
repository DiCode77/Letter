//
//  property.cpp
//  Letter
//
//  Created by DiCode77.
//

#include <property.hpp>

lett::Property<lett::window> &lett::Property<lett::window>::app(lett::App *app){
    this->m_app = app;
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::parent(lett::Several *parent){
    this->m_parent = parent;
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::title(const std::string_view &str){
    this->m_title = std::move(str);
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::point(const lett::Rect<lett::point> &pint){
    this->m_point.SetValue(pint);
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::size(const lett::Rect<lett::size> &size){
    this->m_size.SetValue(size);
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::style(lett::style::window style){
    this->m_style = style;
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::auto_resize(bool is_bool){
    this->m_auto_resize = is_bool;
    return *this;
}

lett::Property<lett::window> &lett::Property<lett::window>::id(const lett::UniqueId &is_id){
    this->m_id = is_id;
    return *this;
}

lett::App *lett::Property<lett::window>::GetApp() const{
    return this->m_app;
}

lett::Several *lett::Property<lett::window>::GetParent() const{
    return this->m_parent;
}

std::string_view lett::Property<lett::window>::GetTitle() const{
    return this->m_title;
}

lett::Rect<lett::point> lett::Property<lett::window>::GetPoint() const{
    return this->m_point;
}

lett::Rect<lett::size> lett::Property<lett::window>::GetSize() const{
    return this->m_size;
}

lett::style::window lett::Property<lett::window>::GetStyle() const{
    return this->m_style;
}

bool lett::Property<lett::window>::GetAutoResize() const{
    return this->m_auto_resize;
}

lett::UniqueId::ulong_t lett::Property<lett::window>::GetId() const{
    return this->m_id.GetId();
}

// class view

lett::Property<lett::view> &lett::Property<lett::view>::parent(lett::Several *parent){
    this->m_parent = parent;
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::title(const std::string_view &str){
    this->m_title = std::move(str);
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::point(const lett::Rect<lett::point> &pint){
    this->m_point.SetValue(pint);
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::size(const lett::Rect<lett::size> &size){
    this->m_size.SetValue(size);
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::style(lett::style::window style){
    this->m_style = style;
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::auto_resize(bool is_bool){
    this->m_auto_resize = is_bool;
    return *this;
}

lett::Property<lett::view> &lett::Property<lett::view>::id(const lett::UniqueId &is_id){
    this->m_id = is_id;
    return *this;
}

lett::Several *lett::Property<lett::view>::GetParent() const{
    return this->m_parent;
}

std::string_view lett::Property<lett::view>::GetTitle() const{
    return this->m_title;
}

lett::Rect<lett::point> lett::Property<lett::view>::GetPoint() const{
    return this->m_point;
}

lett::Rect<lett::size> lett::Property<lett::view>::GetSize() const{
    return this->m_size;
}

lett::style::window lett::Property<lett::view>::GetStyle() const{
    return this->m_style;
}

bool lett::Property<lett::view>::GetAutoResize() const{
    return this->m_auto_resize;
}

lett::UniqueId::ulong_t lett::Property<lett::view>::GetId() const{
    return this->m_id.GetId();
}
