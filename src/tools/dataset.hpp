//
//  dataset.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef dataset_hpp
#define dataset_hpp

#include <unordered_map>
#include <functional>

namespace lett{
class DataSet{
public:
    using DataPair = std::function<bool()>;
private:
    void      *m_view     = nullptr;
    DataSet   *m_parent   = nullptr;
    std::unordered_map<void*, DataPair> m_children;
public:
    DataSet() = default;
    
    void SetView(void*);
    void SetParent(DataSet*);
    void SetChildren(void*, DataPair &&);
    
    void *GetObject();
    void *GetView();
    DataSet *GetParent();
    std::unordered_map<void*, DataPair> &GetChildren();
};
}

#endif
