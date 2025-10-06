#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  std::stack<T> tmp;
  while (pos) {
    tmp.push(top());
    pop();
    --pos;
  }

  push(value);

  while (!tmp.empty()) {
    push(tmp.top());
    tmp.pop();
  }
  
}

#endif
