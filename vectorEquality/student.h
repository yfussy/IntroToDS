#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  if (mSize != other.mSize) return false;
  for (int i = 0; i < mSize; i++) {
    if (mData[i] != other.mData[i]) return false;
  }
  return true;

}

#endif
