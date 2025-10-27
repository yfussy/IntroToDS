#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  T old = mData[pos];
  mData[pos] = value;
  if (mLess(old, value)) {
    fixUp(pos);
  } else {
    fixDown(pos);
  }
}

#endif
