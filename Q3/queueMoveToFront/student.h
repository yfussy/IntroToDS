#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    size_t idx = (mFront + pos) % mCap;
    T tmp = mData[idx];
    while (idx != mFront) {
        size_t prev = (idx - 1 + mCap) % mCap;
        mData[idx] = mData[prev];
        idx = prev;
    }
    mData[mFront] = tmp;
}
#endif
