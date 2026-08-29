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
    using DataPair = std::pair<DataSet*, std::function<bool()>>;
private:
    void    *m_object   = nullptr;
    DataSet *m_parent   = nullptr;
    std::deque<DataPair> m_children;
public:
    DataSet() = default;
    
    void SetObject(void*);
    void SetParent(DataSet*);
    void SetChildren(DataPair &&);
    
    void *GetObject();
    DataSet *GetParent();
    std::deque<DataPair> &GetChildren();
};
}

#endif
