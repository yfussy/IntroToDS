#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  CP::stack<T> tmp;
  for (; first != last; ++first) {
    tmp.push(*first);
  }
  mData = new T[tmp.mCap]();
  mCap = tmp.mCap;
  mSize = tmp.size();
  for (size_t i = 0; i < tmp.size(); ++i) {
    mData[i] = tmp.mData[size() - i - 1];
  }
}

#endif
