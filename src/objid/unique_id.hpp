//
//  unique_id.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef unique_id_hpp
#define unique_id_hpp

#include <atomic>
#include <functional>

namespace lett {

class UniqueIdBase;
class UniqueId{
public:
    using ulong_t = unsigned long;
private:
    std::atomic<ulong_t> m_id;
public:
    UniqueId();
    UniqueId(const ulong_t&);
    UniqueId(const UniqueId&);
    UniqueId(UniqueId&&);
    UniqueId(UniqueIdBase&);
    
    void Increase();
    void Reduce();
    
    ulong_t EnlargeAndRestore();
    ulong_t RestoreAndIncrease();
    ulong_t GetId() const;
    
    bool compare(const UniqueId&) const;
    
    bool operator== (const UniqueId&) const;
    bool operator!= (const UniqueId&) const;
};

class UniqueIdBase : public UniqueId{
public:
    ~UniqueIdBase() = default;
    UniqueIdBase() = default;
    UniqueIdBase(const UniqueIdBase&) = delete;
    UniqueIdBase(UniqueIdBase&&) = delete;
};

static UniqueIdBase UniqueID_NEW;

}

template<>
class std::hash<lett::UniqueId>{
public:
    std::size_t operator()(const lett::UniqueId &is_is) const{
        return std::hash<lett::UniqueId::ulong_t>{}(is_is.GetId());
    }
};


#endif
