#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if (!m || a == b) return false;
  
  if (a < begin() || a >= end()) return false;
  if (b < begin() || b >= end()) return false;

  if (a + m > end() || b + m >  end() ) return false;

  if ((a < b && a + m > b) || (b < a && b + m > a)) return false;

  T tmp;
  for (size_t i = 0; i < m; ++i, ++a, ++b) {
      T tmp = std::move(*a);
      *a = std::move(*b);
      *b = std::move(tmp);
  }
  return true;
}

#endif
