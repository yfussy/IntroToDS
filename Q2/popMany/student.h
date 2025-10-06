#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  while (K && !empty()) {
    pop();
    K--;
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> tmp, result;

  while (K && !empty()) {
    tmp.push(top());
    pop();
    K--;
  }

  while (!tmp.empty()) {
    result.push(tmp.top());
    tmp.pop();
  }
  return result;
}

#endif
