#include <iostream>
#include <string>
#include "queue.h"
#include "student.h"


using std::cin;
using std::cout;
using std::string;

template <typename T,typename Comp>
void test(int a,int b,int c,int round,Comp comp = Comp()) {
  CP::queue<T> q;
  T tmp;
  for (int i = 0;i < a;i++) { cin >> tmp; q.push(tmp); }
  for (int i = 0;i < b;i++) { q.pop(); }
  for (int i = 0;i < c;i++) { cin >> tmp; q.push(tmp); }

  std::vector<size_t> pos;
  for (int i = 0;i < round;i++) {
    size_t m;
    cin >> m;
    pos.resize(m);
    for (int j = 0;j < m;j++) { cin >> pos[j]; }
    cout << q.min_element(pos,comp) << "\n";
  }
}



int main() {
  std::ios_base::sync_with_stdio(false);cin.tie(0);

  int type, comp, a,b,c, round;
  cin >> type >> comp >> a >> b >> c >> round;

  if (type == 0) {
    if (comp == 0) {
      test<int,std::less<int>>(a,b,c,round);
    } else {
      test<int,std::greater<int>>(a,b,c,round);
    }
  } else if (type == 1) {
    if (comp == 0) {
      test<string,std::less<string>>(a,b,c,round);
    } else {
      test<string,std::greater<string>>(a,b,c,round);
    }
  }
}
