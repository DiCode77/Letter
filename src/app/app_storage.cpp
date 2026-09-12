#include <app_storage.hpp>

bool lett::AppStorage::Empty() const{
    return this->m_set_obj.empty();
}

long lett::AppStorage::size() const{
    return static_cast<long>(this->m_set_obj.size());
}

void lett::AppStorage::AddObject(lett::Object *obj){
    this->m_set_obj.insert(obj);
}

lett::Object *lett::AppStorage::GetObject(lett::Object *is_id){
    if (auto it = this->m_set_obj.find(is_id); it != this->m_set_obj.end()){
        return *it;
    }
    return {};
}

bool lett::AppStorage::IsEmpty(lett::Object *is_id) const{
    auto it = this->m_set_obj.find(is_id);
    return it != this->m_set_obj.end() ? true : false;
}

bool lett::AppStorage::RemoveObject(lett::Object *is_id){
    if (auto it = this->m_set_obj.find(is_id); it != this->m_set_obj.end()){
        this->m_set_obj.erase(it);
        return true;
    }
    return false;
}

lett::AppStorage::SetObj_t &lett::AppStorage::GetObjectList(){
    return this->m_set_obj;
}
