// You may include library here
#include <queue>

int depth(node *n)
{
  if (!n) return -1;
  
  int depth = 0;
  std::queue<node*> q;
  q.push(n);
  while (!q.empty()) {
    int sz = q.size();

    for (int i = 0; i < sz; ++i) {
      node* cur = q.front(); q.pop();
      while (cur) {
        if (cur->left_child) q.push(cur->left_child);
        cur = cur->right_sibling;
      }
    }
    
    ++depth;
  }

  return depth - 1;
}