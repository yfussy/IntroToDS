#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  k %= last - first;
  std::reverse(first, first + k);
  std::reverse(first + k, last);
  std::reverse(first, last);
}

#endif
