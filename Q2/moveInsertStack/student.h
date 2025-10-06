#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
	CP::stack<T> tmp;
	while (k && !empty()) {
		tmp.push(top());
		pop();
		--k;
	}
	while (m && !s2.empty()) {
		tmp.push(s2.top());
		s2.pop();
		--m;
	}
	while (!tmp.empty()) {
		push(tmp.top());
		tmp.pop();
	}

}
#endif
