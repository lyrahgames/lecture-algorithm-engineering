#pragma once
#ifndef __ALGORITHM_ENGINEERING_MATRIX_H__
#define __ALGORITHM_ENGINEERING_MATRIX_H__

#include <cassert>

#include <math/vector.h>

namespace algorithm_engineering {

template <class T>
struct matrix {
  matrix(int row_count, int col_count)
      : h(row_count), w(col_count), v(std::vector<T>(row_count * col_count)) {}

  T& operator()(int i, int j) { return v[rm_map(i, j)]; }
  const T& operator()(int i, int j) const { return v[rm_map(i, j)]; }

  T& operator[](int idx) { return v[idx]; }
  const T& operator[](int idx) const { return v[idx]; }

  int rm_map(int i, int j) const { return w * i + j; }

  T* data() { return v.data(); }
  const T* data() const { return v.data(); }

  vector<T>& vdata() { return v; }
  const vector<T>& vdata() const { return v; }

  int rows() const { return h; }
  int cols() const { return w; }
  int size() const { return v.size(); }

 private:
  int h, w;
  vector<T> v;
};

template <class T>
vector<T> operator*(const matrix<T>& m, const vector<T>& v) {
  assert(m.cols() == static_cast<int>(v.size()));

  vector<T> ret(m.rows());

  for (int i = 0; i < m.rows(); i++) {
    ret[i] = 0;

    for (int j = 0; j < m.cols(); j++) {
      ret[i] += m(i, j) * v[j];
    }
  }

  return ret;
}

}  // algorithm_engineering

#endif  // __ALGORITHM_ENGINEERING_MATRIX_H__