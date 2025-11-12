#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
    if (a1 == b1) return;  // nothing to do

    bool a_empty = (a1 == a2);
    bool b_empty = (b1 == b2);
    if (a_empty && b_empty) return;
	


	iterator before_a1 = a1.ptr->prev;
	iterator before_b1 = b1.ptr->prev;
	iterator last_a = a2.ptr->prev;
	iterator last_b = b2.ptr->prev;
	

    if (a_empty) {
        // detach
        before_b1.ptr->next = b2.ptr;
        b2.ptr->prev = before_b1.ptr;

        // insert
        before_a1.ptr->next = b1.ptr;
        b1.ptr->prev = before_a1.ptr;
        last_b.ptr->next = a1.ptr;
        a1.ptr->prev = last_b.ptr;
        return;
    }


    if (b_empty) {
        // detach
        before_a1.ptr->next = a2.ptr;
        a2.ptr->prev = before_a1.ptr;

        // insert
        before_b1.ptr->next = a1.ptr;
        a1.ptr->prev = before_b1.ptr;
        last_a.ptr->next = b1.ptr;
        b1.ptr->prev = last_a.ptr;
        return;
    }

    // handle adjacency
    if (a2 == b1 || b2 == a1) {
		iterator it = a1;
		while (it != mHeader && it != b1) ++it;
		if (it == mHeader) {
			std::swap(a1, b1);
			std::swap(a2, b2);
			std::swap(before_a1, before_b1);
			std::swap(last_a, last_b);
		}

        before_a1.ptr->next = b1.ptr;
        b1.ptr->prev = before_a1.ptr;

        last_b.ptr->next = a1.ptr;
        a1.ptr->prev = last_b.ptr;

        last_a.ptr->next = b2.ptr;
        b2.ptr->prev = last_a.ptr;
        return;
    }

    // detach both blocks
    before_a1.ptr->next = a2.ptr;
    a2.ptr->prev = before_a1.ptr;
    before_b1.ptr->next = b2.ptr;
    b2.ptr->prev = before_b1.ptr;

    // swap
    before_a1.ptr->next = b1.ptr;
    b1.ptr->prev = before_a1.ptr;
    last_b.ptr->next = a2.ptr;
    a2.ptr->prev = last_b.ptr;

    before_b1.ptr->next = a1.ptr;
    a1.ptr->prev = before_b1.ptr;
    last_a.ptr->next = b2.ptr;
    b2.ptr->prev = last_a.ptr;
}

#endif
