#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "queue.h"
#include "student.h"

using std::cin;
using std::cout;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, K, mFront;

  cin >> N >> K >> mFront;

  CP::queue<int> q(N * 1.5, mFront);
  
  std::vector<size_t> removed;
  for (int i = 1; i <= N; i++)
  {
    int x;

    cin >> x;
    q.push(x);
  }

  for (int i = 1; i <= K; ++i) {
    int x;

    cin >> x;
    removed.push_back(x);
  }

  q.remove_many(removed);
  q.print();

  cout << "PASS asd945a1sd21a3x" << "\n";
}
