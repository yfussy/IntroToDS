#include "student.h"
#include "vector-sm.h"
#include <iostream>
#include <vector>

template <typename T> void test() {
  // Prepare pre-defined mData
  int data_sz;
  std::cin >> data_sz;
  std::vector<std::vector<T>> mData;

  while (data_sz--) {
    int len;
    std::cin >> len;
    std::vector<T> inner(len);

    for (int i = 0; i < len; ++i)
      std::cin >> inner[i];

    mData.push_back(inner);
  }

  CP::vector_some_move<T> v(mData);

  // Main judge
  int n, m;
  std::cin >> n >> m;
  int idx = 0;

  while (n--) {
    int t, val;
    std::cin >> t;

    if (t == 1) {
      T _val;
      std::cin >> _val;

      v.push_back(_val);
    }
    if (t == 2) {
      std::cin >> val;
      v.resize(val);
    }
    if (t == 3) {
      std::cin >> val;
      std::cout << v[val] << "\n";
    }
    if (t == 4) {
      int sz;
      std::cin >> val >> sz;
      std::vector<T> value;
      while (sz--) {
        T el;
        std::cin >> el;

        value.push_back(el);
      }

      v.insert(val, value);
    }
  }

  while (m--) {
    for (int i = 0; i < v.size(); ++i) {
      std::cout << v[i] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;

  if (t == 0)
    test<int>();
  if (t == 1)
    test<long long>();
  if (t == 2)
    test<long double>();

  std::cout << "OK huda89yfugifsdiuoshioasd123";
}
