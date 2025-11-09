#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::replace(const T& x, list<T>& y) {
	for (auto it = begin(); it != end(); ) {
		if (*it == x) {
			it = erase(it);
			for (auto jt = y.begin(); jt != y.end(); ++jt) {
				it = insert(it, *jt); // insert before current it
				++it;
			}
		} else {
			++it;
		}
	}
}

#endif