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
    auto &deq = this->GetChildren();
    std::ranges::for_each(deq.begin(), deq.end(), [](lett::DataSet::DataPair &func){
        func();
    });
    
    deq.clear();
    delete this->m_view;
}

lett::Add<lett::view>::Add(const lett::Property<view> &prop) : m_view(new ViewBridge){
    if (!this->IsCreate(prop)){
        return;
    }
}

bool lett::Add<lett::view>::IsCreate(const lett::Property<view> &prop){
    if (this->m_view->GetView() == nil){
        NSView *p_view = (NSView*)prop.GetParent()->GetView();
        if (p_view != nil){
            NSView *new_view = [[NSView alloc] initWithFrame:p_view.bounds];
            new_view.wantsLayer = YES;
            
            this->m_view->SetView(new_view);
            this->SetView(reinterpret_cast<void*>(new_view));

            this->SetParent(prop.GetParent());
            this->GetParent()->SetChildren({[this]() -> bool{
                delete this;
                return this;
            }});
            
            if (prop.GetAutoResize())
                new_view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
            
            [p_view addSubview:new_view];
        }else{
            throw std::runtime_error("No view!");
        }
    }
    return false;
}

lett::Add<lett::view> *lett::Add<lett::view>::Show(){}
