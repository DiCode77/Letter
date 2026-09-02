//
//  window.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef window_hpp
#define window_hpp

#include <element.hpp>
#include <property.hpp>
#include <view.hpp>

#include <ranges>
#include <algorithm>

namespace lett{

template <typename>
class Create;

class window;
class WindowBridge;

template <>
class Create <window> : public Element<Create<window>, window>{
    WindowBridge *m_window_bridge;
public:
    ~Create() override;
    Create() = delete;

    Create(const lett::Property<window>&);
    bool IsCreate(const lett::Property<window>&) override;
    Create *Show() override;
};
};

#endif
