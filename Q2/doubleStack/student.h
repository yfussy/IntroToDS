#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::pop() {
	if (stack_a.empty()) {
    	int half = stack_b.size() / 2;
        std::stack<T> tmp;

        for (int i = 0; i < half; ++i) {
            tmp.push(stack_b.top());
            stack_b.pop();
        }

        while (!stack_b.empty()) {
            stack_a.push(stack_b.top());
            stack_b.pop();
        }

        while (!tmp.empty()) {
            stack_b.push(tmp.top());
            tmp.pop();
        }
	}
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	if (stack_a.empty()) {
    	int half = stack_b.size() / 2;
        std::stack<T> tmp;

        for (int i = 0; i < half; ++i) {
            tmp.push(stack_b.top());
            stack_b.pop();
        }

        while (!stack_b.empty()) {
            stack_a.push(stack_b.top());
            stack_b.pop();
        }

        while (!tmp.empty()) {
            stack_b.push(tmp.top());
            tmp.pop();
        }
	}
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	if (stack_b.empty()) {
    	int half = stack_a.size() / 2;
        std::stack<T> tmp;

        for (int i = 0; i < half; ++i) {
            tmp.push(stack_a.top());
            stack_a.pop();
        }

        while (!stack_a.empty()) {
            stack_b.push(stack_a.top());
            stack_a.pop();
        }

        while (!tmp.empty()) {
            stack_a.push(tmp.top());
            tmp.pop();
        }
	}
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
    if (stack_b.empty()) {
    	int half = stack_a.size() / 2;
        std::stack<T> tmp;

        for (int i = 0; i < half; ++i) {
            tmp.push(stack_a.top());
            stack_a.pop();
        }

        while (!stack_a.empty()) {
            stack_b.push(stack_a.top());
            stack_a.pop();
        }

        while (!tmp.empty()) {
            stack_a.push(tmp.top());
            tmp.pop();
        }
	}
	stack_b.pop();
}
#endif