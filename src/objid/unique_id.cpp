#include <unique_id.hpp>

lett::UniqueId::UniqueId() : m_id(1){};

lett::UniqueId::UniqueId(const ulong_t &val) : lett::UniqueId::UniqueId(){
    this->m_id.store(val, std::memory_order_relaxed);
}

lett::UniqueId::UniqueId(const UniqueId &p_id) : lett::UniqueId::UniqueId(p_id.m_id.load()){}

lett::UniqueId::UniqueId(UniqueId &&r_obj){
    this->m_id.store(r_obj.m_id.load(), std::memory_order_relaxed);
    r_obj.m_id.store(1,  std::memory_order_relaxed);
}

lett::UniqueId::UniqueId(UniqueIdBase &l_obj) : lett::UniqueId::UniqueId(l_obj.GetId()){
    l_obj.Increase();
}

void lett::UniqueId::Increase(){
    this->m_id.fetch_add(1);
}

void lett::UniqueId::Reduce(){
    this->m_id.fetch_sub(1);
}

lett::UniqueId::ulong_t lett::UniqueId::EnlargeAndRestore(){
    this->Increase();
    return this->m_id.load();
}

lett::UniqueId::ulong_t lett::UniqueId::RestoreAndIncrease(){
    return this->m_id.fetch_add(1);
}

lett::UniqueId::ulong_t lett::UniqueId::GetId() const{
    return this->m_id.load();
}

bool lett::UniqueId::compare(const UniqueId &is_id) const{
    return this->GetId() == is_id.GetId();
}

bool lett::UniqueId::operator== (const UniqueId &is_id) const{
    return this->GetId() == is_id.GetId();
}

bool lett::UniqueId::operator!= (const UniqueId &is_id) const{
    return this->GetId() != is_id.GetId();
}

lett::UniqueId &lett::UniqueId::operator= (UniqueIdBase &l_obj){
    this->m_id.fetch_add(l_obj.GetId());
    l_obj.Increase();
    return *this;
}

lett::UniqueId &lett::UniqueId::operator= (const UniqueId &l_obj){
    this->m_id.fetch_add(l_obj.GetId());
    return *this;
}
