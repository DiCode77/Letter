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
#include <window_property.hpp>

#include <ranges>
#include <algorithm>

#include <event_command.hpp>

namespace lett{

template <typename>
class Create;

class window;
class WindowBridge;

template <>
class Create <window> : public Element<Create<window>>{
    WindowBridge *m_window_bridge;
public:
    ~Create() override;
    Create();
    Create(const lett::Property<window>&);
    bool IsCreate(const lett::Property<window>&) override;
    Create *Show() override;
    Create *Hide() override;
    Create *Center() override;
    void   Close() override;
    
    Create *Connect(const lett::EnumId&, lett::FunctionEvent::Func) override;
    Create *DisConnect(const lett::EnumId&) override;
    Create *RunTheFunction(const lett::EnumId&, const lett::Event&) override;
    bool IsConnect(const lett::EnumId&) override;
};
};

#endif
