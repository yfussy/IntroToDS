#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <queue>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  std::queue<size_t> q;
  std::vector<T> result;
  q.push(0);

  size_t level = k;
  while (level--) {
    size_t levelSize = q.size();

    for (size_t i = 0; i < levelSize; ++i) {
      size_t cur = q.front();
      q.pop();

      result.push_back(mData[cur]);

      size_t lChild = cur * 2 + 1;
      size_t rChild = cur * 2 + 2;
      if (lChild < mSize) q.push(lChild);
      if (rChild < mSize) q.push(rChild);
    }
  }
  std::sort(result.begin(), result.end(), mLess);
  return result[result.size() - k];
}

#endif