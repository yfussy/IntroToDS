#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::helper(node *n)
{
    // You MAY write code in this function
    if (!n) return -1;
    
    MappedT lstDiff = helper(n->left);
    MappedT rstDiff = helper(n->right);
    MappedT stDiff = std::max(lstDiff, rstDiff);
    
    MappedT diff;
    if (!n->left || !n->right) {
        diff = -1;;
    } else {
        MappedT lv = n->left->data.second;
        MappedT rv = n->right->data.second;
        diff = std::abs(lv - rv);
    }

    return std::max(stDiff, diff);
}

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::max_value_diff()
{
    return helper(mRoot);
}

/*
 * Roses are red
 * Violets are blue
 * Your BST knowledge will certainly see you through
 * The problem is set to be solvable and fair
 * Just think carefully, and the solution is there!
 */

#endif