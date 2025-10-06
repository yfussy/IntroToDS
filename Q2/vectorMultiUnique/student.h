#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <unordered_set>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  std::sort(itrs.begin(), itrs.end());
  
  std::unordered_set<T> seen;
  std::vector<CP::vector<T>::iterator> eraseIdx;
  int erase_count = 0;
  for (auto &it : itrs) {
    if (!seen.count(*it)) {
      seen.insert(*it);
    } else {
      eraseIdx.push_back(it);
    }
  }

  sort(eraseIdx.rbegin(), eraseIdx.rend());
  for (CP::vector<T>::iterator it : eraseIdx) {
    erase(it);
  }
}

#endif
