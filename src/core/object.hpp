//
//  object.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef object_hpp
#define object_hpp

#include <iostream>

namespace lett {
class Object{
public:
    virtual ~Object(){
        std::cout << "~Object() " << this << std::endl;
    }
};
}

#endif
