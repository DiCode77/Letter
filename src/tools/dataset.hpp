//
//  dataset.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef dataset_hpp
#define dataset_hpp

#include <deque>
#include <functional>

namespace lett{
class DataSet{
public:
    using DataPair = std::function<bool()>;
private:
    void      *m_view     = nullptr;
    DataSet   *m_parent   = nullptr;
    std::deque<DataPair> m_children;
public:
    DataSet() = default;
    
    void SetView(void*);
    void SetParent(DataSet*);
    void SetChildren(DataPair &&);
    
    void *GetView();
    DataSet *GetParent();
    std::deque<DataPair> &GetChildren();
};
}

#endif
