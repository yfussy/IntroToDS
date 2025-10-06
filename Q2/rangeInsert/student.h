#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
    int insertCount = last - first;
    int posIndex = position - begin();
    int newSize = mSize + insertCount;

    T* arr = new T[newSize];

    for (int i = 0; i < posIndex; i++) { 
      arr[i] = mData[i]; 
    }

    for (int i = 0; i < insertCount; i++) { 
      arr[posIndex + i] = *(first + i); 
    }

    for (int i = posIndex; i < mSize; i++) { 
      arr[i + insertCount] = mData[i]; 
    }
    
    delete [] mData;
    mData = arr;
    mCap = newSize;
    mSize = newSize;
}

#endif
