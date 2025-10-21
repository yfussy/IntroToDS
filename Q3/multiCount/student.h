#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::vector<std::pair<T,size_t>> result;
    std::multimap<T, int> kmap;
    if (k.empty()) return result;

    for (int i = 0; i < k.size(); ++i) {
        result.push_back({k[i], 0});
        kmap.insert({k[i], i});
    }

    for (int i = 0; i < mSize; ++i) {
        int idx = (mFront + i) % mCap;
        T &val = mData[idx];

        auto range = kmap.equal_range(val);
        for (auto it = range.first; it != range.second; ++it) {
            result[it->second].second++;
        }
    }

    return result;
}

#endif
