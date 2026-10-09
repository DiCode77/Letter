#include <func_call.hpp>

std::size_t lett::EnumId::GetHash() const{
    return this->m_hash;
}

lett::FunctionEvent::~FunctionEvent(){
    this->ClearAll();
}

lett::FunctionEvent::FunctionEvent(){}

lett::FunctionEvent::FunctionEvent(const EnumId &t, lett::FunctionEvent::Func func){
    this->AddFunc(t, func);
}

bool lett::FunctionEvent::Empty() const{
    return this->m_um_func.empty();
}

std::size_t lett::FunctionEvent::GetSize() const{
    return this->m_um_func.size();
}

bool lett::FunctionEvent::IsFunc(const lett::EnumId &is_id) const{
    return this->m_um_func.contains(is_id.GetHash());
}

void lett::FunctionEvent::AddFunc(const EnumId &id, lett::FunctionEvent::Func func){
    this->m_um_func.insert(std::make_pair(id.GetHash(), std::move(func)));
}

void lett::FunctionEvent::FuncCallWithoutChecking(const EnumId &id, const lett::Event &event){
    this->m_um_func.at(id.GetHash())(event);
}

bool lett::FunctionEvent::FuncCall(const EnumId &id, const lett::Event &arg){
    if (auto it = this->m_um_func.find(id.GetHash()); it != this->m_um_func.end()){
        it->second(arg);
        return true;
    }
    return false;
}

bool lett::FunctionEvent::RemoveFunc(const EnumId &id){
    if (auto it = this->m_um_func.find(id.GetHash()); it != this->m_um_func.end()){
        this->m_um_func.erase(it);
        return true;
    }
    return false;
}

lett::FunctionEvent::Func *lett::FunctionEvent::GetFunc(const EnumId &id){
    if (auto it = this->m_um_func.find(id.GetHash()); it != this->m_um_func.end()){
        return &it->second;
    }
    return nullptr;
}

void lett::FunctionEvent::ClearAll(){
    this->m_um_func.clear();
}
