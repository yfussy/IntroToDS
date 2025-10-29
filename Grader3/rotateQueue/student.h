#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::rotate(int k) {
  if (mSize == 0) return;
    
  size_t shiftAmount = k < 0 ? (-1 * k)%mSize : k%mSize;

  if (mCap == mSize) {
    mFront = (mFront + k) % mSize;
    return;
  }

  if (k > 0) {
    for (size_t i = 0; i < shiftAmount; ++i) {
      mData[(mFront + mSize + i) % mCap] = mData[(mFront + i) % mCap];
    }

    mFront = (mFront + shiftAmount) % mCap;
  } else {
    for (size_t i = 0; i < shiftAmount; ++i) {
      mData[(mFront - 1 - i + mCap) % mCap] = mData[(mFront + mSize - 1 - i + mCap) % mCap];
    }

    mFront = (mFront - shiftAmount + mCap) % mCap;
  }


}

#endif
