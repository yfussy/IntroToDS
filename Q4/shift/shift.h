#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::shift(int k) {
	k %= (int)mSize;
	if (k < 0) k += mSize;

	iterator it = begin().ptr;
	for (size_t i = 0; i < k; ++i) ++it;

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	mHeader->next = it.ptr;
	mHeader->prev = it.ptr->prev;
	it.ptr->prev->next = mHeader;
	it.ptr->prev = mHeader;
}

#endif