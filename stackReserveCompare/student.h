#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    int selfDiff = mCap - mSize, otherDiff = other.mCap - other.mSize;
    if (selfDiff < otherDiff) return -1;
    if (selfDiff == otherDiff) return 0;
    return 1;
}

#endif