#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq() {
  std::unordered_set<T> seen;
  size_t newSize = 0;

  for (size_t i = 0; i < mSize; ++i) {
    if (seen.insert(mData[i]).second) {
      mData[newSize++] = mData[i];
    }
  }

  mSize = newSize;
  mCap = mSize;
}

#endif
