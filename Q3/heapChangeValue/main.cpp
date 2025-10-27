#include <iostream>
#include <vector>
#include "priority_queue.h"
#include "student.h"

template <typename T>
void test(T &pq) {
  int n,m;
  std::cin >> n >> m;
  for (int i = 0;i < n;i++) {
    int x;
    std::cin >> x;
    pq.push(x);
  }

  for (int i = 0;i < m;i++) {
    int pos,value;
    std::cin >> pos >> value;
    pq.change_value(pos,value);
  }

  std::cout << "Size is = " << pq.size() << std::endl;
  while (pq.empty() == false) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << std::endl;
}


int main() {
  std::ios_base::sync_with_stdio(false);std::cin.tie(0);
  int case_num;
  std::cin >> case_num;
  if (case_num == 0) {
    CP::priority_queue<int> pq;
    test(pq);
  } else if (case_num == 1) { 
    CP::priority_queue<int,std::greater<int>> pq;
    test(pq);
  }
}



