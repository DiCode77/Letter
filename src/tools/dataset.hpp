//
//  dataset.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef dataset_hpp
#define dataset_hpp

#include <object.hpp>
#include <unique_id.hpp>
#include <application.hpp>

#include <unordered_map>
#include <functional>

namespace lett{
class DataSet : public lett::Object{
public:
    using DataPair = std::function<bool()>;
private:
    lett::App *m_app      = nullptr;
    void      *m_view     = nullptr;
    DataSet   *m_parent   = nullptr;
    std::unordered_map<void*, DataPair> m_children;
    lett::UniqueId m_id;
public:
    virtual ~DataSet() = default;
    DataSet() = default;
    
    void SetApp(lett::App*);
    void SetView(void*);
    void SetParent(DataSet*);
    void SetChildren(void*, DataPair &&);
    void SetId(const lett::UniqueId&);
    
    lett::App *GetApp();
    void *GetObject();
    void *GetView();
    DataSet *GetParent();
    std::unordered_map<void*, DataPair> &GetChildren();
    lett::UniqueId::ulong_t GetID();
};
}

#endif
