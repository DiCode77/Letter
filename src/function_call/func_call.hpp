//
//  function_call.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef function_call_hpp
#define function_call_hpp

#include <unordered_map>
#include <functional>

#include <event.hpp>

namespace lett{

class EnumId{
    std::size_t m_hash = 0;
public:
    template <typename Te>
    EnumId(const Te &t) : m_hash(this->CalculateTheHash<Te>(t)){}
    EnumId(const EnumId &ev) : m_hash(ev.GetHash()){}
    EnumId(EnumId &&r_ev) = delete;
    std::size_t GetHash() const;
private:
    template <typename Te>
    std::size_t CalculateTheHash(const Te &data){
        std::size_t hash_type  = typeid(Te).hash_code();
        std::size_t hash_value = std::hash<std::decay_t<Te>>{}(data);
        return (hash_type ^ (hash_value + 0x9e3779b97f4a7c15ULL + (hash_type << 6) + (hash_type >> 2)));
    }
};

class FunctionEvent{
public:
    using Func = std::function<void(const lett::Event&)>;
private:
    std::unordered_map<size_t, Func> m_um_func;
public:
    ~FunctionEvent();
    FunctionEvent();
    FunctionEvent(const EnumId&, Func);
    
    bool Empty() const;
    size_t GetSize() const;
    bool IsFunc(const EnumId&) const;
    
    void AddFunc(const EnumId&, Func);
    void FuncCallWithoutChecking(const EnumId&, const lett::Event&);
    bool FuncCall(const EnumId&, const lett::Event&);
    bool RemoveFunc(const EnumId&);
    Func *GetFunc(const EnumId&);
    
    void ClearAll();
};
};

#endif
