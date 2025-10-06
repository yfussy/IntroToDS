#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

#include <algorithm>
template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	if (first > last) return;

	first = std::min(first, mSize);
	last = std::min(last + 1, mSize);
	CP::stack<T> tmp1, tmp2;
	std::reverse(&mData[0] + mSize - last, &mData[0] + mSize - first);

}

#endif
