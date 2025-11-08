#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <unordered_set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    std::unordered_set<T> seen;
    size_t distinct = 0;
    while (a < b) {
        if (seen.insert(*a).second) {
            ++distinct;
        }
        ++a;
    }

    return distinct;
}

#endif