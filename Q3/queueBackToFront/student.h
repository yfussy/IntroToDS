#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
	size_t back = (mFront + mSize - 1) % mCap;
	size_t beforeFront = (mFront + mCap - 1) % mCap;

	if (mData[back] != mData[beforeFront]) {
		mData[beforeFront] = mData[back];
	}
	// 1 2 3 4
	// 4 2 3 4 

	mFront = beforeFront;
}

#endif
