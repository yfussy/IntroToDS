#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "map_bst_lite.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, const KeyT &a, const KeyT &b, std::vector<MappedT> &result) const {
    if (!n) return;
    
    const KeyT &k = n->data.first;

    // k > a : go left
    if (mLess(a, k)) {
        my_recur(n->left, a, b, result);
    }

    // a < k < b (!(k <= a) && !(b <= k)): insert
    if (!mLess(k, a) && !mLess(b, k)) {
        result.push_back(n->data.second);
    }

    // k < b : go right
    if (mLess(k, b)) {
        my_recur(n->right, a, b, result);
    }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<MappedT> CP::map_bst<KeyT, MappedT, CompareT>::value_in_key_range(const KeyT &a, const KeyT &b) const {
	std::vector<MappedT> result;
    my_recur(mRoot, a, b, result);
    return result;
}

#endif
