#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  iterator cur = begin();
  while (cur != end()) {
    iterator next = cur.ptr->next;

    if (*cur == value) {
      cur.ptr->prev->next = cur.ptr->next;
      cur.ptr->next->prev = cur.ptr->prev;

      delete cur.ptr;
      --mSize;
    } 

    cur = next;
  }
}

#endif
