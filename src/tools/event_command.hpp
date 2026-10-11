//
//  event_command.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef event_command_hpp
#define event_command_hpp

namespace lett{
enum class event_window{
    none,
    closing,       // An event triggered when a window is closed.
    collapse,      // An event triggered when the “Minimize Window” button is clicked.
    collapsed,     // An event that is triggered when a window has already been minimized.
    expand,        // An event triggered when a window is maximized.
    resizing,      // An event that is triggered when we change the window size.
    resized,       // When we resize the window and then release the right mouse button, this event is triggered.
    zoom,          // This triggers when you double-click within the Title field.
    
    // The following parameters can completely intercept button events and override their functionality
    intercept_close,    // Intercepting the window close event
    intercept_collapse, //
    intercept_expand,   // Intercepting the window deployment event
    intercept_zoom,     // 
};
};

#endif
