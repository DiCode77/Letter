#include <view.hpp>
#include <view.h>

lett::ViewBridge::~ViewBridge(){
    if (this->m_ns_view != nil){
        [this->m_ns_view release];
        this->m_ns_view = nil;
    }
}

lett::ViewBridge::ViewBridge() : m_ns_view(nil){}

void lett::ViewBridge::SetView(NSView *view){
    if (this->m_ns_view == nil){
        this->m_ns_view = view;
    }
}

NSView *lett::ViewBridge::GetView(){
    return this->m_ns_view;
}

lett::Add<lett::view>::~Add(){
    if (!this->GetChildrenList().Empty()){
        auto &um_list = this->GetChildrenList().GetUMapObjectList();
        for (lett::Object *p_obj : um_list | std::views::values){
            delete p_obj;
        }
        um_list.clear();
    }

    [this->m_view_bridge->GetView() removeFromSuperview];
    
    delete this->m_view_bridge;
}

lett::Add<lett::view>::Add() : m_view_bridge(nullptr){}

lett::Add<lett::view>::Add(const lett::Property<view> &prop) : lett::Add<lett::view>::Add(){
    if (!this->IsCreate(prop)){
        return;
    }
}

bool lett::Add<lett::view>::IsCreate(const lett::Property<view> &prop){
    if (this->m_view_bridge == nullptr){
        if (prop.GetParent() != nullptr){
            
            NSView *p_window_view = reinterpret_cast<NSView*>(dynamic_cast<lett::DataSet*>(prop.GetParent())->GetView());
            if (p_window_view != nil){
                NSRect rect = {};
                
                if (prop.GetPoint() != lett::default_point){
                    rect.origin = NSMakePoint(prop.GetPoint().GetX(), prop.GetPoint().GetY());
                }else{
                    rect.origin = p_window_view.bounds.origin;
                }
                
                if (prop.GetSize() != lett::default_size){
                    rect.size = NSMakeSize(prop.GetSize().GetX(), prop.GetSize().GetY());
                }else{
                    rect.size = p_window_view.bounds.size;
                }
                
                NSView *new_view = [[NSView alloc] initWithFrame:rect];
                new_view.wantsLayer = YES; // Note to self: I need to add this to the properties.
                
                this->m_view_bridge = new ViewBridge();
                
                this->m_view_bridge->SetView(new_view);
                this->SetView(reinterpret_cast<void*>(new_view));
                this->SetId(prop.GetId());
                
                this->SetParent(prop.GetParent());
                this->GetParent()->SetChildren(prop.GetId(), this);
                
                if (prop.GetAutoResize())
                    new_view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
                
                [p_window_view addSubview:new_view];
            }else{
                throw std::runtime_error("No view!");
            }
        }else{
            throw std::runtime_error("Pointer to a bit object is missing!");
        }
    }
    return false;
}

lett::Add<lett::view> *lett::Add<lett::view>::Show(){
    return this;
}

lett::Add<lett::view> *lett::Add<lett::view>::Hide(){
    return this;
}
