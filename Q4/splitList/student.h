void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if (!mSize) return;

    if (mSize == 1) {
        iterator it = begin();

        mHeader->next = mHeader;
        mHeader->prev = mHeader;
        mSize = 0;

        list1.mHeader->prev->next = it.ptr;
        it.ptr->prev = list1.mHeader->prev;
        list1.mHeader->prev = it.ptr;
        it.ptr->next = list1.mHeader;

        mSize = 0;
        list1.mSize += 1;
        return;
    }

    size_t mid = mSize/2;
    
    iterator it1_start = begin();
    iterator it2_start = end();
    for (size_t i = 0; i < mid; ++i) --it2_start;

    iterator it1_end = it2_start.ptr->prev;
    iterator it2_end = mHeader->prev;

    // detach orig
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;

    // connect 1
    list1.mHeader->prev->next = it1_start.ptr;
    it1_start.ptr->prev = list1.mHeader->prev;
    list1.mHeader->prev = it1_end.ptr;
    it1_end.ptr->next = list1.mHeader;
    list2.mSize += mSize - mid; 

    // connect 2
    list2.mHeader->prev->next = it2_start.ptr;
    it2_start.ptr->prev = list2.mHeader->prev;
    list2.mHeader->prev = it2_end.ptr;
    it2_end.ptr->next = list2.mHeader;
    list2.mSize += mid;
}
