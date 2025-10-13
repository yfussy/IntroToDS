#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
	// push_back - fast track
    if (index == mSize) {
        if (mData.empty()) {
            mData.push_back(value);
            aux.push_back(value.size());
        } else {
            mData.back().insert(mData.back().end(), value.begin(), value.end());
            aux.back() += value.size();
        }
        mSize += value.size();
        mCap += value.size();
        return;
    }

	// mData index
    int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
    if (i > 0) index -= aux[i - 1];

    if (index == mData[i].size()) { // push back - fast track
        mData[i].insert(mData[i].end(), value.begin(), value.end());
    } else { // insert middle
        size_t oldSize = mData[i].size();
        size_t tailSize = oldSize - index;

        mData.reserve(mData.size() + 1);
        
        mData.insert(mData.begin() + i + 1, std::vector<T>());
        
        std::vector<T> &tail = mData[i + 1];
        tail.reserve(oldSize - index);
        for (size_t j = index; j < oldSize; ++j) {
            tail.push_back(std::move(mData[i][j]));
        }
        
        // Reserve spcae for inserted value
        mData[i].resize(index);
        mData[i].reserve(index + value.size());
        mData[i].insert(mData[i].end(), value.begin(), value.end());
        
        aux[i] = (i == 0 ? 0 : aux[i - 1]) + mData[i].size();
        aux.insert(aux.begin() + i + 1, aux[i] + mData[i + 1].size());
        for (size_t pos = i + 2; pos < aux.size(); ++pos)
            aux[pos] = aux[pos - 1] + mData[pos].size();
    }

    mSize += value.size();
    mCap += value.size();
}

#endif