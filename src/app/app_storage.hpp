//
//  app_storage.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef app_storage_hpp
#define app_storage_hpp

#include <object.hpp>

#include <set>

namespace lett {

class AppStorage{
    using SetObj_t = std::set<lett::Object*>;
    SetObj_t m_set_obj;
public:
    AppStorage() = default;
    AppStorage(const AppStorage&) = delete;
    AppStorage(AppStorage&&) = delete;
    
    bool Empty() const;
    long size() const;
    void AddObject(lett::Object*);
    lett::Object *GetObject(lett::Object*);
    bool IsEmpty(lett::Object*) const;
    bool RemoveObject(lett::Object*);
    SetObj_t &GetObjectList();
};

}

#endif
