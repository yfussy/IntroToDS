#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <queue>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  for (size_t i = 0; i < mSize; ++i) {
    if (mData[i] == k) return true;
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  std::queue<size_t> q;
  q.push(0);
  size_t level = 0, foundLevel = -1;
  while (!q.empty()) {
    size_t levelSize = q.size();

    for (size_t i = 0; i < levelSize; ++i) {
      size_t cur = q.front();
      q.pop();

      T val = mData[cur];
      if (val == k) foundLevel = level;

      size_t lChild = cur * 2 + 1;
      size_t rChild = cur * 2 + 2;
      if (lChild < mSize) q.push(lChild);
      if (rChild < mSize) q.push(rChild);
    }

    level++;
  }

  return foundLevel;
}

#endif

