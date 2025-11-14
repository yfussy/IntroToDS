#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
  //you MAY need to use this function
  if (!n) return;
  
  if (tmp != level) {
    my_recur(n->right, level, tmp + 1, v);
    my_recur(n->left, level, tmp + 1, v);
    return;
  }

  v.push_back(n->data.first);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  //write your code here
  std::vector<KeyT> v;
  my_recur(mRoot, level, 0, v);
  return v;
}


#endif
