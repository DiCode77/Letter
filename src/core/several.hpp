//
//  several.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef several_hpp
#define several_hpp

#include <object.hpp>
#include <dataset.hpp>

namespace lett{

template <typename>
class Add;
class view;

class Several : public Object, protected lett::DataSet{
public:
    virtual ~Several() = default;
};
}

#endif
