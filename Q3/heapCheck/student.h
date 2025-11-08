#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  for (size_t i = 0; i < mSize; ++i) {
    size_t left = 2*i + 1;
    size_t right = 2*i + 2;

    if (left < mSize && mLess(mData[i], mData[left])) return false;
    if (right < mSize && mLess(mData[i], mData[right])) return false;
  }
  return true;
}

#endif