#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    if (mSize == mCap) return;
    expand(mSize);
}

#endif
