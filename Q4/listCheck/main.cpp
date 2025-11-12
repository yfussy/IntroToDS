#include <iostream>
#include <vector>
#include "list.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  int round;
  cin >> round;
  while (round--) {
    int n;
    cin >> n;
    CP::list<int> l;
    for (int i = 0;i < n;i++) l.push_back((i+1)*10);
    int a,b,c;
    cin >> a >> b >> c;
    if (a > 0) l.messup(a,b,c);
    cout << l.check() << "\n";
  }
}
