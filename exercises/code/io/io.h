#pragma once
#ifndef __ALGORITHM_ENGINEERING_IO_H__
#define __ALGORITHM_ENGINEERING_IO_H__

#include <iostream>

#include <math/matrix.h>
#include <math/vector.h>

template <class T>
inline std::ostream& operator<<(std::ostream& os,
                                const algorithm_engineering::matrix<T>& mat) {
  os << mat.rows() << 'x' << mat.cols() << ":" << std::endl;

  for (int i = 0; i < mat.rows(); i++) {
    for (int j = 0; j < mat.cols(); j++) {
      os << mat(i, j) << "\t";
    }
    os << std::endl;
  }

  return os;
}

template <class T>
inline std::ostream& operator<<(std::ostream& os,
                                const algorithm_engineering::vector<T>& v) {
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    os << v[i] << "\t";
  }
  return os;
}

#endif  // __ALGORITHM_ENGINEERING_IO_H__