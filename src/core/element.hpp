//
//  element.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef element_hpp
#define element_hpp

#include <several.hpp>
#include <property.hpp>

namespace lett{

// Main polymorphic class.
template <typename>
class Element;

// A list of classes that will belong to a specific tool has been announced.
class window;
class view;

// The declaration of the Kolas template, which is part of the letter architecture, has been announced.
template <typename T>
class Create;

template <typename>
class Add;

// Declaration of template classes that serve as a local polymorphic description or an additional description for the main interface.
template <typename Te>
class Overview{
public:
    virtual ~Overview() = default;
    
    virtual Te *Show() = 0;
    virtual Te *Hide() = 0;
};

template <>
class Element <Create<window>> : public Several, public Overview<Create<window>>{ // ?
public:
    ~Element() override = default;
    
    virtual bool IsCreate(const lett::Property<window>&) = 0;
    virtual Create<window> *Center() = 0;
    
    virtual void Close() = 0;
    
};

template <>
class Element <Add<view>> : public Several, public Overview<Add<view>>{
public:
    ~Element() override = default;
    
    virtual bool IsCreate(const lett::Property<view>&) = 0;
};

}

#endif
