//
//  unique_id.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef unique_id_hpp
#define unique_id_hpp

#include <atomic>

namespace lett {
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
    
    void Increase();
    void Reduce();
    
    ulong_t EnlargeAndRestore();
    ulong_t RestoreAndIncrease();
    ulong_t GetId();
};
}

#endif
