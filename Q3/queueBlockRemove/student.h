#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    size_t len = to - from + 1;
    size_t tail = mSize - to - 1;
    if (from < tail) {
        for (size_t i = 0; i < from; ++i) {
            mData[(mFront + to - i) % mCap] = mData[(mFront + from - 1 - i) % mCap];
        }
        mFront = (mFront + len) % mCap;
    } else {
        for (size_t i = 0; i < tail; ++i) {
            mData[(mFront + from + i) % mCap] = mData[(mFront + to + 1 + i) % mCap];
        }
    }
    mSize -= len;
}
#endif