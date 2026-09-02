//
//  property.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef property_hpp
#define property_hpp

#include <string_view>
#include <rect.hpp>
#include <styles.hpp>
#include <dataset.hpp>

namespace lett{

template <typename>
class Property{
    DataSet                 *m_parent = nullptr;
    std::string_view        m_title;
    lett::Rect<lett::point> m_point  = lett::default_point;
    lett::Rect<lett::size>  m_size   = lett::default_size;
    int                     m_style  = 0; // ?
    bool                    m_auto_resize = true;
public:
    Property &parent(DataSet*);
    Property &title(const std::string_view&);
    Property &point(const lett::Rect<lett::point>&);
    Property &size(const lett::Rect<lett::size>&);
    Property &style(int);
    Property &auto_resize(bool);
    
    DataSet *GetParent() const;
    std::string_view GetTitle() const;
    lett::Rect<lett::point> GetPoint() const;
    lett::Rect<lett::size> GetSize() const;
    int GetStyle() const;
    bool GetAutoResize() const;
};

#include <property.inl>
}

#endif
