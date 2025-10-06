#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
	if (!size() && other.size()) return true;
	if (size() && other.size()) {
		if (mData[0] < other.mData[0]) return true;
		if (mData[0] == other.mData[0]) {
			int length = std::min(size(), other.size());
			for (size_t i = 1; i < length; ++i) {
				if (mData[i] < other.mData[i]) return true;
			}
			if (size() < other.size()) return true;
		}

	}
	return false;
}

#endif
