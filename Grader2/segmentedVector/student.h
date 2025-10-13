#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "segmented_vector.h"

template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    for (size_t i = 0; i < mCap; ++i) delete[] mData[i]; 
    delete[] mData;
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    T **arr = new T*[capacity]();
    for (size_t i = 0; i < capacity; ++i) {
        if (i < mCap) {
            arr[i] = new T[blockSize]();
            for (size_t j = 0; j < blockSize; ++j) {
                arr[i][j] = mData[i][j];
            }
        } else {
            arr[i] = new T[blockSize]();
        }
    }
    
    for (size_t i = 0; i < mCap; ++i) delete[] mData[i];
    delete[] mData;
    mData = arr;
    mCap = capacity;
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T& element)
{
    ensureCapacity((mSize / blockSize) + 1);
    for (size_t i = mSize; i > index; --i) {
        (*this)[i] = (*this)[i-1];
    }
    (*this)[index] = element;
    mSize++;
}
template <typename T>
T& CP::SegmentedVector<T>::operator[](int index) const
{
    return mData[index/blockSize][index%blockSize];
}
#endif