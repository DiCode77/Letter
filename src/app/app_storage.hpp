//
//  app_storage.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef app_storage_hpp
#define app_storage_hpp

#include <object.hpp>
#include <unique_id.hpp>

#include <unordered_map>

namespace lett {

class AppStorage{
    using UMapObj_t = std::unordered_map<lett::UniqueId, lett::Object*>;
    UMapObj_t m_umap_obj;
public:
    AppStorage() = default;
    AppStorage(const AppStorage&) = delete;
    AppStorage(AppStorage&&) = delete;
    
    bool Empty() const;
    long Size() const;
    void AddObject(const lett::UniqueId&, lett::Object*);
    lett::Object *GetObject(const lett::UniqueId&);
    bool IsEmpty(const lett::UniqueId&) const;
    bool RemoveObject(const lett::UniqueId&);
    UMapObj_t &GetObjectList();
};

}

#endif
