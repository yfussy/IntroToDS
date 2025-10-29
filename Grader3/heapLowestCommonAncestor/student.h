#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"
#include <set>

template <typename T,typename Comp >
size_t CP::priority_queue<T,Comp>::lca(size_t p, size_t q) const {
  size_t parentP = p;
  size_t parentQ = q;
  std::set<size_t> pAnces;
  pAnces.insert(p);
  while (parentP > 0) {
    parentP = (parentP - 1) / 2;
    pAnces.insert(parentP);
  }

  while (parentQ > 0) {
    if (pAnces.count(parentQ)) return parentQ;
    parentQ = (parentQ - 1) / 2;
  }
  return 0;

}

#endif
