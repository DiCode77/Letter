//
//  event.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef event_hpp
#define event_hpp

#include <rect.hpp>

namespace lett{
class Object;
class DataSet;
struct Storage;

class Event{
    using RectSize  = lett::Rect<lett::size>;
    using RectPoint = lett::Rect<lett::point>;
    
    struct Storage{
        lett::DataSet *m_data_set = nullptr;
        RectPoint m_point = lett::default_point;
        RectSize  m_size  = lett::default_size;
    } *stg;
public:
    ~Event(){
        delete this->stg;
    }
    
    Event() : stg(new Storage()){}
    
    Event(const Storage &ev) : Event(){
        *this->stg = ev;
    }
    
    Event(const Event &ev) : Event(){
        *this->stg = *ev.stg;
    }
    
    Event(Event &&ev) : stg(nullptr){
        this->stg = ev.stg;
        ev.stg = nullptr;
    }
    
    bool GetMain() const;
    long long GetId() const;
    RectPoint GetPoint() const;
    RectSize  GetSize() const;
};
const lett::Event default_event;
}

#endif
