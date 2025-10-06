#include <stdexcept>
#include <iostream>
#include <string>
#include <cassert>
#include "vector.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
void do_check(CP::vector<T> &v,int round) {
  for (int i = 0;i < round;i++) {
    int a,b,k;
    cin >> a >> b >> k;
    assert(a >= 0);
    assert(a <= b);
    assert(b <= (int)v.size());
    assert(0 <= k && k <= (b-a));
    typename CP::vector<T>::iterator first,last;
    first = v.begin() + a;
    last = v.begin() + b;
    v.rotate(first,last,(size_t)k);
  }
}

void do_int(int n,int round) {
  CP::vector<int> v(n);
  for (int i = 0;i < n;i++) {
    v[i] = i*10;
  }
  do_check(v,round);
  for (auto &x:v) {
    cout << x << " ";
  }
  cout << endl;
}

void do_string(int n,int round,int prefix_size) {
  string prefix(prefix_size,'*');
  CP::vector<string> v(n);
  for (int i = 0;i < n;i++) {
    v[i] = prefix + std::to_string(i);
  }
  do_check(v,round);
  for (auto &x:v) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    int type,n,round,size;
    std::cin >> type;
    if (type == 0) {
      cin >> n >> round;
      do_int(n,round);
    } else {
      cin >> n >> round >> size;
      do_string(n,round,size);
    }
}
