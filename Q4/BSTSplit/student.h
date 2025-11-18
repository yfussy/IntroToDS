#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <functional>

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
    CP::map_bst<KeyT,MappedT,CompareT> result;

    node* cur = mRoot;
    node* L = NULL;
    node* R = NULL;
    node* L_tail = NULL;
    node* R_tail = NULL;
    int count = 0;
    while (cur != NULL) {
      std::cout << ++count << std::endl;
        if (cur->data.first < val) {
            node* nxt = cur->right;
            cur->right = NULL;     // detach
            nxt->parent = NULL;
            // if (nxt) nxt->parent = NULL;

            if (L == NULL) L = cur;
            else {
              L_tail->right = cur;
              cur->parent = L_tail;
            }
            L_tail = cur;

            cur = nxt;
        } else {
            node* nxt = cur->left;
            cur->left = NULL;      // detach
            nxt->parent = NULL;
            // if (nxt) nxt->parent = NULL;

            if (R == NULL) R = cur;
            else {
              R_tail->left = cur;
              cur->parent = R_tail;
            }
            R_tail = cur;

            cur = nxt;
        }

    }

    mRoot = L;
    L->parent = mRoot;
    
    result.mRoot = R;
    R->parent = result.mRoot;

    return result;
}

#endif
