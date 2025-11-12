#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  iterator it = begin();
  iterator prev = mHeader;

  size_t count = 0;

  while (true) {
    if (it.ptr == mHeader) break;

    if (count > mSize) return false;

    if (!it.ptr || !prev.ptr) return false;

    if (prev.ptr->next != it.ptr) return false;
    if (it.ptr->prev != prev.ptr) return false;

    prev = it;
    ++it;
    ++count;
  }

  if (it.ptr != mHeader) return false;

  if (mSize == 0) {
    if (mHeader->next != mHeader || mHeader->prev != mHeader) return false;
  } else {
    if (prev.ptr->next != it.ptr) return false;
    if (it.ptr->prev != prev.ptr) return false;
  }

  if (count != mSize) return false;

  return true;
}
#endif
