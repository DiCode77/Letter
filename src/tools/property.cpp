#include <property.hpp>

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
