#ifndef ALGORITHM_ENGINEERING_AXPY_H_
#define ALGORITHM_ENGINEERING_AXPY_H_

template <class T>
void axpy(int n, float a, const T* x, T* y) {
  for (int i = 0; i < n; ++i) {
    y[i] += a * x[i];
  }
}

#endif  // ALGORITHM_ENGINEERING_AXPY_H_