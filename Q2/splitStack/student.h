#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
	if (k < size()) {
		std::vector<std::vector<T>> result;
		int x = 0;
		for (int i = 0; i < k; ++i) {
			std::vector<T> split;
			for (int j = 0; x + j < size(); j += k) {
				split.push_back(mData[mSize - 1 - x - j]);
			}
			std::reverse(split.begin(), split.end());
			result.push_back(split);
			++x;
		}
		return result;
	}
}

#endif

