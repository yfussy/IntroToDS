#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <functional>

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
    CP::map_bst<KeyT,MappedT,CompareT> result;

    if (mRoot == NULL) return result;

    node* cur = mRoot;
    node* L = NULL;
    node* R = NULL;
    node* Ltail = NULL;
    node* Rtail = NULL;

    while (cur != NULL) {
        if (cur->data.first < val) {
            node* nxt = cur->right;
            cur->right = NULL;     // detach
            if (nxt != NULL) nxt->parent = NULL;

            if (L == NULL) L = cur;
            else {
              Ltail->right = cur;
              cur->parent = Ltail;
            }
            Ltail = cur;

            cur = nxt;
        } else {
            node* nxt = cur->left;
            cur->left = NULL;      // detach
            if (nxt != NULL) nxt->parent = NULL;

            if (R == NULL) R = cur;
            else {
              Rtail->left = cur;
              cur->parent = Rtail;
            }
            Rtail = cur;

            cur = nxt;
        }

    }

    mRoot = L;
    if (mRoot) mRoot->parent = NULL;

    result.mRoot = R;
    if (result.mRoot) result.mRoot->parent = NULL;

    return result;
}

#endif
