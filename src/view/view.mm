#include <view.hpp>
#include <view.h>

lett::Add<lett::view>::~Add(){
    delete this->m_view;
}

lett::Add<lett::view>::Add(const lett::Property<view> &prop) : m_view(new ViewBridge){
    this->IsCreate(prop);
}

bool lett::Add<lett::view>::IsCreate(const lett::Property<view> &prop){
    if (this->m_view->GetNSView() == nil){
        
        NSView *p_view = (NSView*)prop.GetParent()->GetView();
        if (p_view != nil){
            NSView *new_view = [[NSView alloc] initWithFrame:p_view.bounds];
            new_view.wantsLayer = YES;
            
            this->m_view->SetNSView(new_view);
            this->SetView(reinterpret_cast<void*>(new_view));

            this->SetParent(prop.GetParent());
            this->GetParent()->SetChildren({this, [this]() -> bool{
                delete this;
                return this;
            }});
            
            [p_view addSubview:new_view];
        }else{
            throw std::runtime_error("No view!");
        }
    }
}

lett::Add<lett::view> *lett::Add<lett::view>::Show(){}
