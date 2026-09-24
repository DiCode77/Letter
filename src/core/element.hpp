//
//  element.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef element_hpp
#define element_hpp

#include <dataset.hpp>
#include <property.hpp>

namespace lett{
template <typename TemplType, typename PropType>
class Element : public DataSet{
public:
    virtual ~Element() = default;
    virtual bool IsCreate(const lett::Property<PropType>&) = 0;
    virtual TemplType *Show() = 0;
    virtual TemplType *Hide() = 0;
    virtual TemplType *Center() = 0;
    virtual void       Close() = 0;
//    virtual TemplType *Minimize() = 0;
 //   virtual TemplType *DeMinimize() = 0;
//    virtual TemplType *Zoom() = 0;
   // virtual TemplType *Destroy() = 0; // ?
//    virtual lett::App *GetAppLifeSpan(){
//        return nullptr;
//    }
};
}

#endif
