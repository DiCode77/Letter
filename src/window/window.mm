#include <window.hpp>
#include <window.h>

@implementation WindowInterface

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_oem_window = nil;
    }
    
    return self;
}

- (BOOL)windowShouldClose:(NSWindow *)sender{
    return true;
}
@end

lett::WindowBridge::~WindowBridge(){
    if (this->m_ns_window != nil){
        if (this->m_interface != nil){
            [this->m_ns_window setDelegate:nil];
            [this->m_interface release];
            this->m_interface = nil;
        }
        [this->m_ns_window release];
        this->m_ns_window = nil;
    }
}

lett::WindowBridge::WindowBridge() : m_ns_window(nil){}

void lett::WindowBridge::SetWindow(NSWindow *window, Create<lett::window> *p_window){
    if (this->m_ns_window == nil){
        this->m_ns_window = window;
        this->m_interface = [[WindowInterface alloc] init];
        
        [this->m_interface setM_oem_window:p_window];
        [this->m_ns_window setDelegate:this->m_interface];
    }
}

NSWindow *lett::WindowBridge::GetWindow(){
    return this->m_ns_window;
}

lett::Create<lett::window>::~Create(){
    std::ranges::for_each(this->GetChildren().begin(), this->GetChildren().end(), [](lett::DataSet::DataPair &func){
        func();
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
        this->m_window_bridge->SetWindow(window, this);
        
        if (prop.GetParent() != nullptr){
            this->SetParent(prop.GetParent());
            this->GetParent()->SetChildren({[this](){
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
    [this->m_window_bridge->GetWindow() makeKeyAndOrderFront:nil];
    return this;
}

lett::Create<lett::window> *lett::Create<lett::window>::Hide(){
    [this->m_window_bridge->GetWindow() orderOut:nil];
    return this;
}

lett::Create<lett::window> *lett::Create<lett::window>::Close(){
    [this->m_window_bridge->GetWindow() close];
    return this;
}

lett::Create<lett::window> *lett::Create<lett::window>::Destroy(){
    return this;
}
