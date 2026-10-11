#include <window.hpp>
#include <window.h>

@implementation WindowInterface

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_oem_object = nil;
        _m_data_set   = nil;
    }
    
    return self;
}

- (void)dealloc{
    [super dealloc];
}

- (lett::Rect<lett::point>)get_rect_point:(NSWindow*)window{
    if (window != nil){
        return {
            static_cast<lett::val_t>([window frame].origin.x),
            static_cast<lett::val_t>([window frame].origin.y)
        };
    }
    return lett::default_point;
}

- (lett::Rect<lett::size>)get_rect_size:(NSWindow*)window{
    if (window != nil){
        return {
            static_cast<lett::val_t>([window frame].size.width),
            static_cast<lett::val_t>([window frame].size.height)
        };
    }
    return lett::default_size;
}

// The delegation method is triggered when the red navigation button is pressed.
- (BOOL)windowShouldClose:(NSWindow *)sender{
    auto &func_obj = self.m_data_set->GetFuncEvent();
    if (bool is_run = func_obj.FuncCall(lett::event_window::closing, lett::Event({
        .m_sender = reinterpret_cast<void*>(sender),
        .m_data_set = self.m_data_set,
        .m_point    = std::move([self get_rect_point:sender]),
        .m_size     = std::move([self get_rect_size:sender])
    })); is_run == true){
        return false;
    }
    return true;
}

- (void)windowWillClose:(NSNotification *)notification{
    if (self.m_oem_object != nil && self.m_data_set != nil){
        if (self.m_data_set->GetMain() == true){
            if (self.m_data_set->GetApp() != nullptr){
                self.m_data_set->GetApp()->DestroyObject(self.m_data_set->GetID());
            }else{
                throw std::runtime_error("The property was not registered!");
            }
        }else{
            self.m_data_set->GetParent()->GetChildrenList().RemoveObject(self.m_data_set->GetID());
            delete self.m_oem_object;
        }
    }else{
        throw std::range_error("The class is not polymorphic!");
    }
}

- (BOOL)windowShouldZoom:(NSWindow *)window toFrame:(NSRect)newFrame{
    if (const bool is_run = self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::intercept_zoom, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point    = std::move([self get_rect_point:window]),
        .m_size     = std::move([self get_rect_size:window])
    })); is_run == true){
        return false;
    }else{
        self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::zoom, lett::Event({
            .m_data_set = self.m_data_set,
            .m_point = {
                static_cast<lett::val_t>(newFrame.origin.x),
                static_cast<lett::val_t>(newFrame.origin.y)
            },
            .m_size = {
                static_cast<lett::val_t>(newFrame.size.width),
                static_cast<lett::val_t>(newFrame.size.height)
            },
        }));
    }
    return true;
}

- (NSRect)windowWillUseStandardFrame:(NSWindow *)window defaultFrame:(NSRect)newFrame{
    return newFrame;
}

// The delegation method is triggered when the yellow navigation button is pressed. #1
- (void)windowWillMiniaturize:(NSNotification *)notification{
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::collapse, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point = std::move([self get_rect_point:(NSWindow*)notification.object]),
        .m_size  = std::move([self get_rect_size:(NSWindow*)notification.object]),
    }));
}

// The delegation method is triggered when the yellow button is pressed and the hiding process is complete. #2
- (void)windowDidMiniaturize:(NSNotification *)notification{
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::collapsed, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point = std::move([self get_rect_point:(NSWindow*)notification.object]),
        .m_size  = std::move([self get_rect_size:(NSWindow*)notification.object]),
    }));
}

// The delegate method is triggered when the yellow button is clicked and the window is expanded. #3
- (void)windowDidDeminiaturize:(NSNotification *)notification{
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::expand, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point = std::move([self get_rect_point:(NSWindow*)notification.object]),
        .m_size  = std::move([self get_rect_size:(NSWindow*)notification.object]),
    }));
}

// The delegation method is triggered when the red button is pressed. #1
- (void)windowDidResize:(NSNotification *)notification{
    NSWindow *window = (__bridge NSWindow*)notification.object;
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::resizing, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point    = std::move([self get_rect_point:window]),
        .m_size     = std::move([self get_rect_size:window])
    }));
}

// The delegation method is triggered when the red button is pressed. #2
- (void)windowDidEndLiveResize:(NSNotification *)notification{
    NSWindow *window = (__bridge NSWindow*)notification.object;
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::resizing, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point    = std::move([self get_rect_point:window]),
        .m_size     = std::move([self get_rect_size:window])
    }));
    
    self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::resized, lett::Event({
        .m_data_set = self.m_data_set,
        .m_point    = std::move([self get_rect_point:window]),
        .m_size     = std::move([self get_rect_size:window])
    }));
}

@end

@implementation ButtonDelegate

- (instancetype)init{
    self = [super init];
    
    if (self){
        _m_data_set = nil;
    }
    
    return self;
}

- (void)dealloc{
    [super dealloc];
}

- (void)set_um_storage:(NSButton*)button_key : (const StorageTargetAndAction&) stg{
    _m_um_storage_button.insert(std::make_pair(button_key, stg));
}

- (void)window_close:(id)sender{
    if (auto it_storage = _m_um_storage_button.find(static_cast<NSButton*>(sender)); it_storage != _m_um_storage_button.end()){
        if (const bool is_run = self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::intercept_close, lett::Event({
            .m_sender = reinterpret_cast<void*>(sender),
            .m_data_set = self.m_data_set,
        })); is_run != true){
            [reinterpret_cast<NSApplication*>(self.m_data_set->GetApp()->GetNSApp()) sendAction:it_storage->second.selector
                                                                                             to:it_storage->second.target
                                                                                           from:it_storage->first];
        }
    }
}

- (void)window_minimaze:(id)sender{
    if (auto it_storage = _m_um_storage_button.find(static_cast<NSButton*>(sender)); it_storage != _m_um_storage_button.end()){
        if (const bool is_run = self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::intercept_collapse, lett::Event({
            .m_sender = reinterpret_cast<void*>(sender),
            .m_data_set = self.m_data_set,
        })); is_run != true){
            [reinterpret_cast<NSApplication*>(self.m_data_set->GetApp()->GetNSApp()) sendAction:it_storage->second.selector
                                                                                             to:it_storage->second.target
                                                                                           from:it_storage->first];
        }
    }
}

- (void)window_zoom:(id)sender{
    if (auto it_storage = _m_um_storage_button.find(static_cast<NSButton*>(sender)); it_storage != _m_um_storage_button.end()){
        if (const bool is_run = self.m_data_set->GetFuncEvent().FuncCall(lett::event_window::intercept_expand, lett::Event({
            .m_sender = reinterpret_cast<void*>(sender),
            .m_data_set = self.m_data_set,
        })); is_run != true){
            [reinterpret_cast<NSApplication*>(self.m_data_set->GetApp()->GetNSApp()) sendAction:it_storage->second.selector
                                                                                             to:it_storage->second.target
                                                                                           from:it_storage->first];
        }
    }
}


@end

lett::WindowBridge::~WindowBridge(){
    if (!this->m_button_delegate.m_um_storage_button.empty()){ // ?
        std::ranges::for_each(this->m_button_delegate.m_um_storage_button.begin(), this->m_button_delegate.m_um_storage_button.end(), [](const std::pair<NSButton*, StorageTargetAndAction> &pair){
            [pair.first setAction:pair.second.selector];
            [pair.first setTarget:pair.second.target];
        });
    }
    
    if (this->m_ns_window != nil){
        [this->m_ns_window setDelegate:nil];
        [this->m_ns_window close];
        //[this->m_ns_window release];
        
        this->m_ns_window = nil;
    }
    
    if (this->m_interface != nil){
        [this->m_interface release];
        this->m_interface = nil;
    }
    
    if (this->m_button_delegate != nil){
        this->m_button_delegate.m_um_storage_button.clear();
        [this->m_button_delegate release];
        this->m_button_delegate = nil;
    }
}

lett::WindowBridge::WindowBridge() : m_ns_window(nil), m_interface(nil), m_button_delegate(nil){}

void lett::WindowBridge::SetWindow(NSWindow *window, lett::Object *p_obj, lett::DataSet *p_dset){
    if (this->m_ns_window == nil && this->m_interface == nil){
        this->m_ns_window = window;
        
        this->m_interface = [[WindowInterface alloc] init];
        
        [this->m_interface setM_oem_object:p_obj];
        [this->m_interface setM_data_set:p_dset];
        [this->m_ns_window setDelegate:this->m_interface];
        
        this->m_button_delegate = [[ButtonDelegate alloc] init];
        [this->m_button_delegate setM_data_set:p_dset];
        
        NSButton *button = nil;

        // We specify our delegate for the close button.
        // We specify our delegate for the collapse button.
        // We specify our delegate for the expand button.
        for (NSUInteger b_st = NSWindowButton::NSWindowCloseButton; b_st <= NSWindowButton::NSWindowZoomButton; b_st++){
            button = [window standardWindowButton:(NSWindowButton)b_st];
            [this->m_button_delegate set_um_storage:button :{
                [button action], [button target]
            }];
            [button setTarget:this->m_button_delegate];
            [button setAction:@selector(window_close:)];
        }
        
        /*
         Basically, here's how it works: immediately after creating the window,
         I delegate its buttons, and then I check whether the corresponding flag with the methods to be referenced has been created; if not, I continue executing the code;
         if so, I perform the redirection, and in this case, the standard close, minimize, and maximize events can be ignored.
         */
        
    }else{
        throw std::runtime_error("One of the objects has already been created!");
    }
}

NSWindow *lett::WindowBridge::GetWindow(){
    return this->m_ns_window;
}

WindowInterface *lett::WindowBridge::GetInterface(){
    return this->m_interface;
}

lett::Create<lett::window>::~Create(){
    auto &obj = this->GetChildrenList();
    if (!obj.Empty()){
        for (lett::Object *p_obj : obj.GetUMapObjectList() | std::views::values){
            delete p_obj;
        }
        obj.GetUMapObjectList().clear();
    }
    delete this->m_window_bridge;
}

lett::Create<lett::window>::Create() : m_window_bridge(nullptr){}

lett::Create<lett::window>::Create(const lett::Property<lett::window> &prop) : lett::Create<lett::window>::Create(){
    if (!this->IsCreate(prop)){
        return;
    }
}

bool lett::Create<lett::window>::IsCreate(const lett::Property<lett::window> &prop){
    // We check whether `window_bridge` has already been created to avoid creating it again and prevent memory leaks.
    if (this->m_window_bridge == nullptr){
        // We get an object from the application to register the window.
        if (prop.GetParent() != nullptr){
            this->SetMain(false);
            this->SetApp(dynamic_cast<DataSet*>(prop.GetParent())->GetApp());
            this->SetParent(prop.GetParent()); // We get a pointer to the parent, if there is one )))
        }else{
            this->SetMain(true);
            this->SetApp(prop.GetApp());
        }
        
        // This is a very important step, since without registering the facility, it cannot be properly decommissioned and closed.
        if (this->GetApp() == nullptr){
            throw std::runtime_error("The pointer that is supposed to store the address of the Application object is empty!");
        }
        
        this->m_window_bridge = new WindowBridge();
        
        NSWindow *window = [NSWindow alloc];
        NSRect rect = {};
        
        if (prop.GetPoint() != lett::default_point){
            rect.origin = NSMakePoint(prop.GetSize().GetX(), prop.GetPoint().GetY());
        }else{
            rect.origin = {}; // ?
        }
        
        if (prop.GetSize() != lett::default_size){
            rect.size = NSMakeSize(prop.GetSize().GetX(), prop.GetSize().GetY());
        }else{
            rect.size = {}; // ?
        }
        
        [window initWithContentRect:rect styleMask:(NSWindowStyleMask)prop.GetStyle() backing:NSBackingStoreBuffered defer:NO];
        [window setReleasedWhenClosed:YES];
        [window setTitle:[NSString stringWithUTF8String:prop.GetTitle().data()]];
        
        this->SetView(reinterpret_cast<void*>(window.contentView));
        this->m_window_bridge->SetWindow(window, this, this);
        this->SetId(prop.GetId());
        
        // Registering a property.
        if (this->GetMain()){
            this->GetApp()->GetAppStorageQuantity().AddObject(prop.GetId(), this);
        }else{
            this->GetParent()->SetChildren(prop.GetId(), this);
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

lett::Create<lett::window> *lett::Create<lett::window>::Center(){
    [this->m_window_bridge->GetWindow() center];
    return this;
}

void lett::Create<lett::window>::Close(){
    [this->m_window_bridge->GetWindow() close];
}

void lett::Create<lett::window>::MinimazeTheWindow(){
    [this->m_window_bridge->GetWindow() miniaturize:nil];
}

void lett::Create<lett::window>::DeminiaturizeTheWindow(){
    [this->m_window_bridge->GetWindow() deminiaturize:nil];
}

bool lett::Create<lett::window>::IsMiniaturizedWindow(){
    return static_cast<bool>([this->m_window_bridge->GetWindow() isMiniaturized]);
}

void lett::Create<lett::window>::ToggleFullScreen(){
    [this->m_window_bridge->GetWindow() toggleFullScreen:nil];
}

bool lett::Create<lett::window>::IsFullScreen(){ // ?
    return false;
}

void lett::Create<lett::window>::Zoom(){
    [this->m_window_bridge->GetWindow() zoom:nil];
}

bool lett::Create<lett::window>::IsZoom(){
    return static_cast<bool>([this->m_window_bridge->GetWindow() isZoomed]);
}

lett::Create<lett::window> *lett::Create<lett::window>::Connect(const lett::EnumId &is_id, lett::FunctionEvent::Func func){
    this->SetFuncEvent(is_id, func);
    return this;
}

lett::Create<lett::window> *lett::Create<lett::window>::DisConnect(const lett::EnumId &is_id){
    this->GetFuncEvent().RemoveFunc(is_id);
    return this;
}

lett::Create<lett::window> *lett::Create<lett::window>::RunTheFunction(const lett::EnumId &is_id, const lett::Event &event){
    this->GetFuncEvent().FuncCall(is_id, event);
    return this;
}

bool lett::Create<lett::window>::IsConnect(const lett::EnumId &is_id){
    return this->GetFuncEvent().IsFunc(is_id);
}

lett::Create<lett::window> *lett::Create<lett::window>::SetPoint(const lett::Rect<lett::point>&){ // ?
}

lett::Create<lett::window> *lett::Create<lett::window>::SetSize(const lett::Rect<lett::size>&){ // ?
}

lett::Rect<lett::point> lett::Create<lett::window>::GetPoint() const{
    return [this->m_window_bridge->GetInterface() get_rect_point:this->m_window_bridge->GetWindow()];
}


lett::Rect<lett::size> lett::Create<lett::window>::GetSize() const{
    return [this->m_window_bridge->GetInterface() get_rect_size:this->m_window_bridge->GetWindow()];
}
