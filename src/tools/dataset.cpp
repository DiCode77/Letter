#include <dataset.hpp>

void lett::DataSet::SetApp(lett::App *app){
    this->m_app = app;
}

void lett::DataSet::SetView(void *view){
    this->m_view = view;
}

void lett::DataSet::SetParent(lett::DataSet *parent){
    this->m_parent = parent;
}

void lett::DataSet::SetChildren(void *obj, DataPair &&r_ch){
    this->m_children.insert(std::make_pair(obj, std::move(r_ch)));
}

void lett::DataSet::SetId(const lett::UniqueId &is_id){
    this->m_id = is_id;
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

std::unordered_map<void*, lett::DataSet::DataPair> &lett::DataSet::GetChildren(){
    return this->m_children;
}

lett::UniqueId::ulong_t lett::DataSet::GetID(){
    return this->m_id.GetId();
}
