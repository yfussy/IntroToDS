#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  if (a == b) return a;

  iterator ptr = a;
  --b;

  while (a != b) {
    std::swap(*a, *b);
    if (++a == b) break; // even
    --b;
  }

  return ptr;
}

#endif