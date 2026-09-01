//
//  view.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef view_hpp
#define view_hpp

#include <property.hpp>
#include <element.hpp>
#include <stdexcept>

namespace lett{

template <typename>
class Add;

class view;
class ViewBridge;

template <>
class Add <view> : public Element<Add<view>, view>{
    ViewBridge *m_view;
public:
    ~Add() override;
    Add(const lett::Property<view>&);
    bool IsCreate(const lett::Property<view>&) override;
    Add *Show() override;
};

};

#endif
