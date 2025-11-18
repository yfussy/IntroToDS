#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if (!n) return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (!mRoot) return std::pair<KeyT,MappedT>();

  size_t lst = process(mRoot->left);
  if (lst) {
    mRoot->left->parent = left.mRoot;
    left.mRoot = mRoot->left;
  }
  left.mSize = lst;

  size_t rst = process(mRoot->right);
  if (rst) {
    mRoot->right->parent = right.mRoot;
    right.mRoot = mRoot->right;
  }
  right.mSize = rst;
  
  mRoot->left = mRoot->right = NULL;
  mSize = 1;
  return std::make_pair(mRoot->data.first, mRoot->data.second);
}

#endif

