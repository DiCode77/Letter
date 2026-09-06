#include <dataset.hpp>

void lett::DataSet::SetView(void *view){
    this->m_view = view;
}

void lett::DataSet::SetParent(lett::DataSet *parent){
    this->m_parent = parent;
}

void lett::DataSet::SetChildren(void *obj, DataPair &&r_ch){
    this->m_children.insert(std::make_pair(obj, std::move(r_ch)));
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
