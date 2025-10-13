#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

template<typename T>
void CP::stack<T>::push(const T &value) {
    ensureCapacity(mSize + 1);
    mData[mSize++] = value;
    
    while (!aux_stack_2.empty()) {
        aux_stack_2.pop();
    }
    aux_stack_1.push({1, value});
    return ;
} 

template <typename T>
void CP::stack<T>::pop() {
    //Do not modify this line
    if (size() == 0) throw std::out_of_range("index of out range") ;
  
    //You can write your code below here
    while (!aux_stack_2.empty()) {
        aux_stack_2.pop();
    }

    aux_stack_1.push({0, top()});
    --mSize;
    return ;
}

template <typename T>
void CP::stack<T>::undo() {
    if (aux_stack_1.empty()) return;
  
    std::pair<int, T> op = aux_stack_1.top();
    aux_stack_2.push(op);

    // do: 1 pop 0 push
    if (op.first) {
        --mSize;
    } else {
        ensureCapacity(mSize + 1);
        mData[mSize++] = op.second;
    }

    aux_stack_1.pop();
    return ;
};

template <typename T>
void CP::stack<T>::redo() {
    if (aux_stack_2.empty()) return;
    std::pair<int, T> op = aux_stack_2.top();
    aux_stack_2.pop();
    aux_stack_1.push(op);

    // do: 1 push 0 pop
    if (op.first) {
        ensureCapacity(mSize + 1);
        mData[mSize++] = op.second;
    } else {
        --mSize;
    }

    return ;
}

#endif