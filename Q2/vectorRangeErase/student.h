#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <algorithm>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
	std::sort(ranges.begin(), ranges.end(), [](const auto &a, const auto &b) { return a.first < b.first; });
	
	std::vector<std::pair<iterator, iterator>> merged;
	merged.push_back(ranges[0]);
	for (size_t i = 1;i < ranges.size(); ++i) {
		auto &last = merged.back();
		if (ranges[i].first <= last.second) {
			last.second = std::max(last.second, ranges[i].second);
		} else {
			merged.push_back(ranges[i]);
		}
	}

	for (auto it = merged.rbegin(); it != merged.rend(); ++it) {
		int erase_count = it->second - it->first;
		int start = it->first - begin();
		int end  = it->second - begin();

		for (size_t i = end; i < mSize; ++i) {
			mData[i - erase_count] = mData[i];
		}

		mSize -= erase_count;
	}
}

#endif
