//
//  dataset.hpp
//  Letter
//
//  Created by DiCode77.
//

#ifndef dataset_hpp
#define dataset_hpp

#include <deque>

namespace lett{
class DataSet{
public:
    void    *m_object   = nullptr;
    DataSet *m_parent   = nullptr;
    std::deque<DataSet*> m_children;
};
}

#endif
