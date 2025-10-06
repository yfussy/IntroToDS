#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    CP::stack<T> tmp;
    while (b + 1) {
        tmp.push(top());
        if (a <= 0) tmp.push(top());
        pop();
        --a;
        --b;
    }

    while (!tmp.empty()) {
        push(tmp.top());
        tmp.pop();
    }
}

#endif
