#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"
#include <unordered_set>

template <typename T,typename Comp >
size_t CP::priority_queue<T,Comp>::lca(size_t p, size_t q) {
  /*
        Secure the subtasks instead of chasing full marks.
        With best intentions, from dungeonowner :)
  */

  while (p != q) {
      if (p > q) p = (p - 1) / 2;
      else       q = (q - 1) / 2;
  }

  size_t l = p;
  mData[l] = mData[mSize - 1];
  mSize--;

  size_t parent = (l - 1)/2;
  size_t left = l * 2 + 1;
  size_t right = l * 2 + 2;
  if (l > 0 && mLess(mData[parent], mData[l])) {
    fixUp(l);
  } else if (
    (left < mSize && mLess(mData[l], mData[left])) ||
    (right < mSize && mLess(mData[l], mData[right]))
  ) {
    fixDown(l);
  }

  return l;
}

#endif
