#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  return v.back();
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  v.erase(prev(v.end()));
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  v.insert(depth > v.size() ? v.begin() : v.end() - depth, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  for (const T &e : w) {
    v.push_back(e);
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  while(top() != e && v.size() != 0) {
    pop();
  }
}

#endif

