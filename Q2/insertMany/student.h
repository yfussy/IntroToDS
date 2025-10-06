#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(), data.end(), [&] (const auto &a, const auto &b) { return a.first > b.first; });

  int n = mSize;
  int m = data.size();
  ensureCapacity(n + m);

  T *arr = new T[n+m];
  int mi = n + m, ni = n, i = 0;

  while (mi > 0) {
    if (i < m && data[i].first == ni) {
      arr[--mi] = data[i++].second;
    } else {
      arr[--mi] = mData[--ni];
    }
  }

  delete[] mData;
  mData = arr;
  mSize = n + m;
}

#endif
