#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  T *tmpData = other.mData;
  int tmpSize = other.mSize;
  int tmpCap = other.mCap;
  other.mData = mData;
  other.mSize = mSize;
  other.mCap = mCap;
  mData = tmpData;
  mSize = tmpSize;
  mCap = tmpCap;
}

#endif
