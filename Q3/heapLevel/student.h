#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <vector>
#include <algorithm>
#include <queue>
#include "priority_queue.h"

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
    std::vector<T> result;

    std::queue<size_t> q;
    q.push(0);
    size_t level = 0;

    while (!q.empty()) {
        size_t levelSize = q.size();

        for (size_t i = 0; i < levelSize; ++i) {
            size_t cur = q.front();
            q.pop();

            size_t lChild = cur * 2 + 1;
            size_t rChild = cur * 2 + 2;

            if (level == k) {
                result.push_back(mData[cur]);
            } else {
                if (lChild < mSize) q.push(lChild);
                if (rChild < mSize) q.push(rChild);
            }
        }

        if (level == k) break;
        ++level;
    }

    std::sort(result.rbegin(), result.rend(), mLess);

    return result;
}

#endif
