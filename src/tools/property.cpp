#include <property.hpp>

lett::Property<lett::window> &lett::Property<lett::window>::parent(DataSet *parent){
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

lett::Property<lett::window> &lett::Property<lett::window>::style(int style){
    this->m_style = style;
    return *this;
}

lett::DataSet *lett::Property<lett::window>::GetParent() const{
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

int lett::Property<lett::window>::GetStyle() const{
    return this->m_style;
}
