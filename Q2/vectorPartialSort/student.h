#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include <set>
#include <algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  std::vector<T> sorted;
  for (iterator it : pos) {
    sorted.push_back(*it);
  }

  std::sort(sorted.begin(), sorted.end(), [&](const auto &a, const auto &b) { return comp(a, b); });
  std::sort(pos.begin(), pos.end());

  for (size_t i = 0; i < pos.size(); ++i) {
    mData[pos[i] - begin()] = sorted[i];
  }
}

#endif
