//
//  element.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef element_hpp
#define element_hpp

#include <dataset.hpp>
#include <property.hpp>

namespace lett{

template <typename>
class Element;

class window;
class view;

template <typename T>
class Create;

template <typename>
class Add;

template <>
class Element <Create<window>> : public DataSet{ // ?
public:
    ~Element() override = default;
    
    virtual bool IsCreate(const lett::Property<window>&) = 0;
    virtual Create<window> *Show() = 0;
    virtual Create<window> *Hide() = 0;
    virtual Create<window> *Center(){}
    
    virtual void Close() = 0;
};

template <>
class Element <Add<view>> : protected DataSet{
public:
    ~Element() override = default;
    
    virtual bool IsCreate(const lett::Property<view>&) = 0;
    virtual Add<view> *Show() = 0;
    virtual Add<view> *Hide() = 0;
    virtual Add<view> *Center(){}
    
    virtual void Close() = 0;
};


}

#endif
