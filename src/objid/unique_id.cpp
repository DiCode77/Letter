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

lett::UniqueId::ulong_t lett::UniqueId::GetId(){
    return this->m_id.load();
}
