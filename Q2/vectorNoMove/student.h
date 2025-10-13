#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  auto it = std::upper_bound(aux.begin(), aux.end(), idx);
  size_t i = it - aux.begin();
  return mData[i][idx - (i == 0 ? 0 : aux[i - 1])];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  size_t start_index = 0;
  if (!aux.empty()) start_index = aux.back();
  aux.push_back(start_index + mData.back().size());
}

#endif
