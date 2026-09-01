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
            this->m_view->SetNSView([[NSView alloc] initWithFrame:NSMakeRect(50, 50, 300, 200)]);
            this->m_view->GetNSView().wantsLayer = YES;
            this->m_view->GetNSView().layer.backgroundColor = [[NSColor systemBlueColor] CGColor];
            
            this->SetView(reinterpret_cast<void*>(this->m_view->GetNSView()));
            
            this->SetParent(prop.GetParent());
            this->GetParent()->SetChildren({this, [this]() -> bool{
                delete this;
                return this;
            }});
            
            [p_view addSubview:this->m_view->GetNSView()];
        }else{
            throw std::runtime_error("No view!");
        }
    }
}

lett::Add<lett::view> *lett::Add<lett::view>::Show(){}
