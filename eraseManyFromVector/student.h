#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int dec = 0;
  for (auto p : pos) {
    erase(begin() + p - dec);
    dec++;
  }
}

#endif
