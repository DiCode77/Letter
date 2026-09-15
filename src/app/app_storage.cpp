#include <app_storage.hpp>

bool lett::AppStorage::Empty() const{
    return this->m_umap_obj.empty();
}

long lett::AppStorage::Size() const{
    return static_cast<long>(this->m_umap_obj.size());
}

void lett::AppStorage::AddObject(const lett::UniqueId &id, lett::Object *obj){
    this->m_umap_obj.insert(std::make_pair(id, obj));
}

lett::Object *lett::AppStorage::GetObject(const lett::UniqueId &is_id){
    if (auto it = this->m_umap_obj.find(is_id); it != this->m_umap_obj.end()){
        return it->second;
    }
    return nullptr;
}

bool lett::AppStorage::IsEmpty(const lett::UniqueId &is_id) const{
    auto it = this->m_umap_obj.find(is_id);
    return it != this->m_umap_obj.end() ? true : false;
}

bool lett::AppStorage::RemoveObject(const lett::UniqueId &is_id){
    if (auto it = this->m_umap_obj.find(is_id); it != this->m_umap_obj.end()){
        this->m_umap_obj.erase(it);
        return true;
    }
    return false;
}

lett::AppStorage::UMapObj_t &lett::AppStorage::GetObjectList(){
    return this->m_umap_obj;
}
