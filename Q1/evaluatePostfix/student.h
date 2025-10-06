#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>
#include <map>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
	int num1, num2;
	stack<int> s;
    for (auto& p : v) {
        if (p.first) {
            s.push(p.second);
        } else {
            int num2 = s.top(); s.pop();
            int num1 = s.top(); s.pop();
            switch (p.second) {
                case 0: s.push(num1 + num2); break;
                case 1: s.push(num1 - num2); break;
                case 2: s.push(num1 * num2); break;
                case 3: s.push(num1 / num2); break;
            }
        }
    }

	return s.top();
}

#endif
