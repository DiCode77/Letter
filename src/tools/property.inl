//
//  property.inl
//  Letter
//
//  Created by DiCode77.
//

template <typename T>
lett::Property<T> &lett::Property<T>::parent(DataSet *parent){
    this->m_parent = parent;
    return *this;
}

template <typename T>
lett::Property<T> &lett::Property<T>::title(const std::string_view &str){
    this->m_title = std::move(str);
    return *this;
}

template <typename T>
lett::Property<T> &lett::Property<T>::point(const lett::Rect<lett::point> &pint){
    this->m_point.SetValue(pint);
    return *this;
}

template <typename T>
lett::Property<T> &lett::Property<T>::size(const lett::Rect<lett::size> &size){
    this->m_size.SetValue(size);
    return *this;
}

template <typename T>
lett::Property<T> &lett::Property<T>::style(int style){
    this->m_style = style;
    return *this;
}

template <typename T>
lett::Property<T> &lett::Property<T>::auto_resize(bool is_bool){
    this->m_auto_resize = is_bool;
    return *this;
}

template <typename T>
lett::DataSet *lett::Property<T>::GetParent() const{
    return this->m_parent;
}

template <typename T>
std::string_view lett::Property<T>::GetTitle() const{
    return this->m_title;
}

template <typename T>
lett::Rect<lett::point> lett::Property<T>::GetPoint() const{
    return this->m_point;
}

template <typename T>
lett::Rect<lett::size> lett::Property<T>::GetSize() const{
    return this->m_size;
}

template <typename T>
int lett::Property<T>::GetStyle() const{
    return this->m_style;
}

template <typename T>
bool lett::Property<T>::GetAutoResize() const{
    return this->m_auto_resize;
}
