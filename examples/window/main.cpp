#include <iostream>
#include <rect.hpp>
#include <window.hpp>
#include <application.hpp>

class MyApp : public lett::App{
    lett::Create<lett::window> *m_window;
    lett::Create<lett::window> *m_window_2;
    
    lett::Add<lett::view> *m_view;
public:
    MyApp(){
        this->m_window = new lett::Create<lett::window>(lett::Property<lett::window>{}
                                                        .title("My App")
                                                        .size({800, 600})
                                                        .point({200, 200})
                                                        .style(int(lett::style::window::MaskTitled
                                                                   | lett::style::window::MaskClosable
                                                                   | lett::style::window::MaskMiniaturizable
                                                                   | lett::style::window::MaskResizable)));
        
        this->m_view = new lett::Add<lett::view>(lett::Property<lett::view>{}.parent(this->m_window));
//        
//        
//        this->m_window_2 = new lett::Create<lett::window>(lett::Property<lett::window>{}
//                                                          .parent( this->m_view)
//                                                          .title("My App")
//                                                          .size({800, 600})
//                                                          .point({200, 200})
//                                                          .style(int(lett::style::window::MaskTitled
//                                                                   | lett::style::window::MaskClosable
//                                                                   | lett::style::window::MaskMiniaturizable
//                                                                   | lett::style::window::MaskResizable)));
    }
    ~MyApp(){
        delete this->m_window;
    }
};

int main(){
    MyApp *app = new MyApp(); 
    app->Run();
    delete app;
    
    
    lett::Rect<lett::point> point1 = {13, 3434};
    lett::Rect<lett::point> point2;
    
    lett::Rect<lett::size> size1 = {100, 232};
    
    point2 = point1;
    
    lett::Rect<lett::point> size4 = {100, 232};
    
    if (0){
        
        lett::Create<lett::window> *window = new lett::Create<lett::window>(lett::Property<lett::window>{}
                                                                            .title("Hello")
                                                                            .size({10, 30})
                                                                            .point({200, 300}));
        window->Show();
        
      //  lett::Element<lett::Create<lett::window>, lett::window> *window2 = new lett::Create<lett::window>(lett::Property<lett::window>{
            
      //  });
    }
    
    
    std::cout << "Hello Letter!" << std::endl;
    
    return 0;
}
