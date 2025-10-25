#include "queue.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

template <typename T>
void createQueue() {
	CP::queue<T> q;

	while(true){
		char cmd;
		cin >> cmd;

		if(cmd == 's') {
			cout << q.size() << "\n";
		} else if (cmd == 'u') {
			T X;
			cin >> X;
			q.push(X);
		} else if (cmd == 'o') {
			q.pop();
		} else if (cmd == 'f') {
			cout << q.front() << "\n";
		} else if (cmd == 'b') {
			cout << q.back() << "\n";
		} else if (cmd == 'i') {
			int p,m;
			T e;
			cin >> p >> m >> e;
			q.block_insert(p, m, e);
		} else {
			break;
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const std::string KEY = "GJtQrwC6OfA6oYU";
	
	int dataType;
	cin >> dataType;

	if(dataType == 0){
		createQueue<int>();
	} else if(dataType == 1){
		createQueue<std::string>();
	}

	cout << KEY << "\n";
}