#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if (!n) return 0;

    int lh = my_recur(n->left, aux);
    int rh = my_recur(n->right, aux);

    if (lh + rh > aux) aux = lh + rh;

    return std::max(lh, rh) + 1;
	
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    if (!mRoot) return -1;

    int aux = 0;
    my_recur(mRoot, aux);
    return aux;
	
}

#endif