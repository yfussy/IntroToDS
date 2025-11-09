#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  if (a == b) return;

  node* cur = a.ptr;

  while (cur != b.ptr) {
    node* next = cur->next;

    if (cur->data == value) {
      // erase
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      mSize--;

      // push front
      cur->prev = output.mHeader;
      cur->next = output.mHeader->next;
      output.mHeader->next->prev = cur;
      output.mHeader->next = cur; 
      ++output.mSize;
    }

    cur = next;
  }

}

#endif