#include <func_call.hpp>

std::size_t lett::EnumId::GetHash() const{
    return this->m_hash;
}

lett::FunctionEvent::FunctionEvent(){}

lett::FunctionEvent::FunctionEvent(const EnumId &t, std::function<void(const lett::Event&)> func){
    this->AddFunc(t, func);
}

bool lett::FunctionEvent::Empty() const{
    return this->m_um_func.empty();
}

std::size_t lett::FunctionEvent::GetSize() const{
    return this->m_um_func.size();
}

void lett::FunctionEvent::AddFunc(const EnumId &id, std::function<void(const lett::Event&)> func){
    this->m_um_func.insert(std::make_pair(id.GetHash(), std::move(func)));
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

std::function<void(const lett::Event&)> *lett::FunctionEvent::GetFunc(const EnumId &id){
    if (auto it = this->m_um_func.find(id.GetHash()); it != this->m_um_func.end()){
        return &it->second;
    }
    return nullptr;
}

void lett::FunctionEvent::ClearAll(){
    this->m_um_func.clear();
}
