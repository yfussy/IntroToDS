#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
    std::sort(pos.begin(), pos.end());

    size_t newSize = mSize - pos.size();
    T *arr = new T[newSize];

    auto it = pos.begin();

    for (size_t i = 0, j = 0; j < mSize; ++j) {
        if (it != pos.end() && j == *it) {
            ++it;
        } else {
            arr[i++] = mData[(mFront + j) % mCap];
        }
    }

    delete[] mData;
    mData = arr;
    mCap = newSize;
    mFront = 0;
    mSize = newSize;

}

#endif
