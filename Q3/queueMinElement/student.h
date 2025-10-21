#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
	bool found = false;
	T min;
	for (auto idx : pos) {
		if (idx >= mSize) continue; // skip invalid

        T &cur = mData[(mFront + idx) % mCap];
        if (!found) {
            min = cur;
            found = true;
        } else if (comp(cur, min)) {
            min = cur;
        }
	}
	return min;
}

#endif
