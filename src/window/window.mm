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

- (void)dealloc{
    [super dealloc];
}

// The delegation method is triggered when the red navigation button is pressed.
- (BOOL)windowShouldClose:(NSWindow *)sender{
    return true;
}

- (void)windowWillClose:(NSNotification *)notification{
    if (self.m_oem_window != nil){
        if (self.m_oem_window->GetApp() != nullptr){
            self.m_oem_window->GetApp()->DestroyObject(self.m_oem_window->GetID());
        }else{
            throw std::runtime_error("The property was not registered!");
        }
    }
}

- (BOOL)windowShouldZoom:(NSWindow *)window toFrame:(NSRect)newFrame{
    return true;
}

- (NSRect)windowWillUseStandardFrame:(NSWindow *)window defaultFrame:(NSRect)newFrame{
    return newFrame;
}

// The delegation method is triggered when the yellow navigation button is pressed. #1
- (void)windowWillMiniaturize:(NSNotification *)notification{}

// The delegation method is triggered when the yellow button is pressed and the hiding process is complete. #2
- (void)windowDidMiniaturize:(NSNotification *)notification{}

// The delegate method is triggered when the yellow button is clicked and the window is expanded. #3
- (void)windowDidDeminiaturize:(NSNotification *)notification{}

// The delegation method is triggered when the red button is pressed. #1
- (void)windowDidResize:(NSNotification *)notification{}

// The delegation method is triggered when the red button is pressed. #2
- (void)windowDidEndLiveResize:(NSNotification *)notification{}

@end

lett::WindowBridge::~WindowBridge(){
    if (this->m_ns_window != nil){
        [this->m_ns_window setDelegate:nil];
        [this->m_ns_window close];
        [this->m_ns_window release];
        
        this->m_ns_window = nil;
    }
    
    if (this->m_interface != nil){
        [this->m_interface release];
        this->m_interface = nil;
    }
}

lett::WindowBridge::WindowBridge() : m_ns_window(nil), m_interface(nil){}

void lett::WindowBridge::SetWindow(NSWindow *window, Create<lett::window> *p_window){
    if (this->m_ns_window == nil && this->m_interface == nil){
        this->m_ns_window = window;
        this->m_interface = [[WindowInterface alloc] init];
        
        [this->m_interface setM_oem_window:p_window];
        [this->m_ns_window setDelegate:this->m_interface];
    }else{
        throw std::runtime_error("One of the objects has already been created!");
    }
}

NSWindow *lett::WindowBridge::GetWindow(){
    return this->m_ns_window;
}

lett::Create<lett::window>::~Create(){
    delete this->m_window_bridge;
}

lett::Create<lett::window>::Create(const lett::Property<lett::window> &prop) : m_window_bridge(nullptr)/*, m_app(prop.GetApp()) */{
    if (!this->IsCreate(prop)){
        return;
    }
}

bool lett::Create<lett::window>::IsCreate(const lett::Property<lett::window> &prop){
    // We check whether `window_bridge` has already been created to avoid creating it again and prevent memory leaks.
    if (this->m_window_bridge == nullptr){
        // We get an object from the application to register the window.
        if (prop.GetParent() != nullptr){
            this->SetApp(prop.GetParent()->GetApp());
            
            // We get a pointer to the parent, if there is one )))
            this->SetParent(prop.GetParent());
        }else{
            this->SetApp(prop.GetApp());
        }
        
        // This is a very important step, since without registering the facility, it cannot be properly decommissioned and closed.
        if (this->GetApp() == nullptr){
            throw std::runtime_error("The pointer that is supposed to store the address of the Application object is empty!");
        }
        
        this->m_window_bridge = new WindowBridge();
        
        NSWindow *window = [NSWindow alloc];
        NSRect rect = NSMakeRect(prop.GetSize().GetX(), prop.GetSize().GetY(), prop.GetPoint().GetX(), prop.GetPoint().GetY());
        
        [window initWithContentRect:rect styleMask:(NSWindowStyleMask)prop.GetStyle() backing:NSBackingStoreBuffered defer:NO];
        [window setTitle:[NSString stringWithUTF8String:prop.GetTitle().data()]];
        
        this->SetView(reinterpret_cast<void*>(window.contentView));
        this->m_window_bridge->SetWindow(window, this);
        this->SetId(prop.GetId());
        
        // Registering a property.
        this->GetApp()->GetAppStorageQuantity().AddObject(prop.GetId(), this);
        
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

lett::Create<lett::window> *lett::Create<lett::window>::Center(){
    [this->m_window_bridge->GetWindow() center];
    return this;
}

void lett::Create<lett::window>::Close(){
    [this->m_window_bridge->GetWindow() close];
}
