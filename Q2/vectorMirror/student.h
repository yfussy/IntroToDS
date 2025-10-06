#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  mSize *= 2;
  size_t s = (mSize > 2 * mCap) ? mSize : 2 * mCap;

  T *arr = new T[mSize]();
  for (size_t i = 0;i < mSize/2;i++) {
    arr[i] = mData[i];
  }
  for (size_t i = 0;i < mSize/2;i++) {
    arr[mSize - i - 1] = mData[i];
  }
  delete [] mData;
  mData = arr;
  mCap = mSize;
}

#endif
