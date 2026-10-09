#include <event.hpp>
#include <dataset.hpp>

bool lett::Event::GetMain() const{
    return (this->stg != nullptr) ? this->stg->m_data_set->GetMain() : false;
}

long long lett::Event::GetId() const{
    return (this->stg != nullptr) ? this->stg->m_data_set->GetID() : 0;
}

lett::Event::RectPoint lett::Event::GetPoint() const{
    return this->stg->m_point;
}

lett::Event::RectSize lett::Event::GetSize() const{
    return this->stg->m_size;
}
