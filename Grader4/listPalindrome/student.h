#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"
#include <cmath>

template<typename T>
size_t CP::list<T>::longest_palindrome() {
  
  iterator L = begin();
  for (size_t i = 0; i < mSize/2 - 1; ++i) L++;

  iterator R = begin();
  for (size_t i = 0; i < mSize/2 + mSize%2; ++i) R++;
  
  size_t result = mSize % 2 == 0 ? 0 : 1;

  if (!result && *L != *R) return 1;

  while (*L == *R) {
    result += 2;
    --L;
    ++R;
  }
  
  return result;
}

#endif