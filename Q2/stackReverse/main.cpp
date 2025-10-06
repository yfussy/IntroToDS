#include "stack.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int first, last;
	int N = 6;
	for (int i = 0; i < 6; ++i) {
		cin >> first >> last;

		CP::stack<int > s;
		for(int i=1;i<=N;i++)
			s.push(i);

		s.reverse(first, last);

		s.print();
	}
}