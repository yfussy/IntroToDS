#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
	size_t baseSize = size() / k, remainder = size() % k;
	size_t s, start = 0;
	std::vector<std::vector<T>> result;
	for (int i = 1; i <= k; ++i) {
		s = (i <= remainder) ? baseSize + 1 : baseSize;
		std::vector<T> extract;
		for (int j = 0; j < s; ++j) {
			extract.push_back(mData[size() - 1 - start - j]);
		}
		start += s;
		result.push_back(extract);
	}
	return result;
}
#endif
