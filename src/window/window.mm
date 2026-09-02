#include <window.hpp>
#include <window.h>

lett::Create<lett::window>::~Create(){
    std::ranges::for_each(this->GetChildren().begin(), this->GetChildren().end(), [](lett::DataSet::DataPair &p){
        p.second();
    });
    this->GetChildren().clear();
    
    delete this->m_window_bridge;
}

lett::Create<lett::window>::Create(const lett::Property<lett::window> &prop){
    if (!this->IsCreate(prop)){
        return;
    }
}


bool lett::Create<lett::window>::IsCreate(const lett::Property<lett::window> &prop){
    if (this->m_window_bridge == nullptr){
        this->m_window_bridge = new WindowBridge();

        NSWindow *window = [NSWindow alloc];
        NSRect rect = NSMakeRect(prop.GetSize().GetX(), prop.GetSize().GetY(), prop.GetPoint().GetX(), prop.GetPoint().GetY());
        
        [window initWithContentRect:rect styleMask:(NSWindowStyleMask)prop.GetStyle() backing:NSBackingStoreBuffered defer:NO];
        [window setTitle:[NSString stringWithUTF8String:prop.GetTitle().data()]];
        [window makeKeyAndOrderFront:nil];
        
        this->SetView(reinterpret_cast<void*>(window.contentView));
     //   this->SetObject(reinterpret_cast<void*>(window)); // ?
        
        this->m_window_bridge->SetWindow(window);
        
        if (prop.GetParent() != nullptr){
            this->SetParent(prop.GetParent());
            this->GetParent()->SetChildren({this, [this](){
                delete this;
                return true;
            }});
            
        }else{
            this->SetParent(nullptr);
        }
        return true;
    }
    return false;
}

lett::Create<lett::window> *lett::Create<lett::window>::Show(){
    return this;
}
