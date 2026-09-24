#include <dataset.hpp>

bool lett::DataSet::SetMain(bool is_m){
    this->m_is_main = is_m;
}

void lett::DataSet::SetApp(lett::App *app){
    this->m_app = app;
}

void lett::DataSet::SetView(void *view){
    this->m_view = view;
}

void lett::DataSet::SetParent(lett::DataSet *parent){
    this->m_parent = parent;
}

void lett::DataSet::SetChildren(const lett::UniqueId &is_id, lett::Object *obj){
    this->m_children.AddObject(is_id, obj);
}

void lett::DataSet::SetId(const lett::UniqueId &is_id){
    this->m_id = is_id;
}

bool lett::DataSet::GetMain() const{
    return this->m_is_main;
}

lett::App *lett::DataSet::GetApp(){
    return this->m_app;
}

void *lett::DataSet::GetView(){
    return this->m_view;
}

lett::DataSet *lett::DataSet::GetParent(){
    return this->m_parent;
}

lett::AppStorage &lett::DataSet::GetChildrenList(){
    return this->m_children;
}

lett::Object *lett::DataSet::GetChildrenId(const lett::UniqueId &is_id){
    return this->m_children.GetObject(is_id);
}

lett::UniqueId::ulong_t lett::DataSet::GetID(){
    return this->m_id.GetId();
}
