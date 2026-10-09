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
#include <several.hpp>
#include <application.hpp>
#include <unique_id.hpp>

namespace lett{

template <typename>
class Property;

class window;
class view;

class AppPropBase{
protected:
    lett::App *m_app = nullptr;
public:
    virtual ~AppPropBase() = default;
    virtual AppPropBase &app(lett::App*) = 0;
    virtual lett::App *GetApp() const = 0;
};

class ParentPropBase{
protected:
    lett::Several *m_parent = nullptr;
public:
    virtual ~ParentPropBase() = default;
    virtual ParentPropBase &parent(lett::Several*) = 0;
    virtual lett::Several *GetParent() const = 0;
};

class TitlePropBase{
protected:
    std::string_view m_title = lett::default_title;
public:
    virtual ~TitlePropBase() = default;
    virtual TitlePropBase &title(const std::string_view&) = 0;
    virtual std::string_view GetTitle() const = 0;
};

class RectPropBase{
protected:
    lett::Rect<lett::point> m_point  = lett::default_point;
    lett::Rect<lett::size>  m_size   = lett::default_size;
public:
    virtual ~RectPropBase() = default;
    virtual RectPropBase &point(const lett::Rect<lett::point>&) = 0;
    virtual RectPropBase &size(const lett::Rect<lett::size>&) = 0;
    virtual lett::Rect<lett::point> GetPoint() const = 0;
    virtual lett::Rect<lett::size> GetSize() const = 0;
};

class StylePropBase{
protected:
    lett::style::window m_style = lett::style::default_window_style;
    bool m_auto_resize = true;
public:
    virtual ~StylePropBase() = default;
    virtual StylePropBase &style(lett::style::window) = 0;
    virtual StylePropBase &auto_resize(bool) = 0;
    virtual lett::style::window GetStyle() const = 0;
    virtual bool GetAutoResize() const = 0;
};

template <>
class Property <window> final : public AppPropBase, public ParentPropBase, public TitlePropBase, public RectPropBase, public StylePropBase{
private:
    lett::UniqueId m_id = lett::UniqueID_NEW;
public:
    ~Property() = default;
    
    Property &app(lett::App*) override;
    Property &parent(lett::Several*) override;
    Property &title(const std::string_view&) override;
    Property &point(const lett::Rect<lett::point>&) override;
    Property &size(const lett::Rect<lett::size>&) override;
    Property &style(lett::style::window) override;
    Property &auto_resize(bool) override;
    Property &id(const lett::UniqueId&);
    
    lett::App *GetApp() const override;
    lett::Several *GetParent() const override;
    std::string_view GetTitle() const override;
    lett::Rect<lett::point> GetPoint() const override;
    lett::Rect<lett::size> GetSize() const override;
    lett::style::window GetStyle() const override;
    bool GetAutoResize() const override;
    lett::UniqueId::ulong_t GetId() const;
};

template <>
class Property <view> final : public ParentPropBase, public TitlePropBase, public RectPropBase, public StylePropBase{
private:
    lett::UniqueId m_id = lett::UniqueID_NEW;
public:
    ~Property() = default;
    
    Property &parent(lett::Several*) override;
    Property &title(const std::string_view&) override;
    Property &point(const lett::Rect<lett::point>&) override;
    Property &size(const lett::Rect<lett::size>&) override;
    Property &style(lett::style::window) override;
    Property &auto_resize(bool) override;
    Property &id(const lett::UniqueId&);
    
    lett::Several *GetParent() const override;
    std::string_view GetTitle() const override;
    lett::Rect<lett::point> GetPoint() const override;
    lett::Rect<lett::size> GetSize() const override;
    lett::style::window GetStyle() const override;
    bool GetAutoResize() const override;
    lett::UniqueId::ulong_t GetId() const;
};

}

#endif
