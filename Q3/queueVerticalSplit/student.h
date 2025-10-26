#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
	size_t baseSize = size() / k, remainder = size() % k;
	size_t s, start = 0;
	for (size_t i = 1; i <= k; ++i) {
		s = (i <= remainder) ? baseSize + 1 : baseSize;
		std::queue<T> result;
		for (size_t j = 0; j < s; ++j) {
			result.push(mData[(mFront + start + j) % mCap]);
		}
		start += s;
		output.push_back(result);
	}
}

#endif
