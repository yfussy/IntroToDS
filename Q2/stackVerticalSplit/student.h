#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
	size_t baseSize = size() / k, remainder = size() % k;
	size_t s, start = 0;
	for (int i = 1; i <= k; ++i) {
		s = (i <= remainder) ? baseSize + 1 : baseSize;
		std::stack<T> result;
		start += s;
		for (int j = 0; j < s; ++j) {
			result.push(mData[size() - start + j]);
		}
		output.push_back(result);
	}
}

#endif
