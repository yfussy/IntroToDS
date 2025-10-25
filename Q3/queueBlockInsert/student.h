#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	ensureCapacity(mSize + m);

	if (p < mSize / 2) {
		// shift left part (front side)
		for (size_t i = 0; i < p; ++i) 
			mData[(mFront - m + i + mCap) % mCap] = mData[(mFront + i) % mCap];
		mFront = (mFront - m + mCap) % mCap;
	} else {
		// shift right part (back side)
		for (size_t i = mSize; i > p; --i) 
			mData[(mFront + i - 1 + m) % mCap] = mData[(mFront + i - 1) % mCap];
	}
	for (size_t i = 0; i < m; ++i) 
		mData[(mFront + p + i) % mCap] = element;
	mSize += m;
}

#endif
