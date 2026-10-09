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
#include <app_storage.hpp>
#include <func_call.hpp>

#include <unordered_map>
#include <functional>

namespace lett{

class DataSet{
    bool       m_is_main  = false;
    lett::App *m_app      = nullptr;
    void      *m_view     = nullptr;
    DataSet   *m_parent   = nullptr;
    lett::AppStorage m_children;
    lett::UniqueId m_id;
    lett::FunctionEvent m_func_event;
public:
    virtual ~DataSet() = default;
    DataSet() = default;
    
    bool SetMain(bool);
    void SetApp(lett::App*);
    void SetView(void*);
    void SetParent(DataSet*);
    void SetChildren(const lett::UniqueId&, lett::Object*);
    void SetId(const lett::UniqueId&);
    void SetFuncEvent(const lett::EnumId&, lett::FunctionEvent::Func);
    
    bool GetMain() const;
    lett::App *GetApp();
    void *GetObject();
    void *GetView();
    DataSet *GetParent();
    lett::AppStorage &GetChildrenList();
    lett::Object *GetChildrenId(const lett::UniqueId&);
    lett::UniqueId::ulong_t GetID() const;
    lett::FunctionEvent &GetFuncEvent();
};
}

#endif
