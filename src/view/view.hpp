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
#include <ranges>
#include <algorithm>

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
    Add() = delete;
    Add(const lett::Property<view>&);
    bool IsCreate(const lett::Property<view>&) override;
    Add *Show() override;
    Add *Hide() override;
    Add *Close() override;
    Add *Destroy() override;
};

};

#endif
