#ifndef ALGORITHM_ENGINEERING_GEMV_H_
#define ALGORITHM_ENGINEERING_GEMV_H_

template <class T>
void gemv(int n, const T* matrix, const T* x, T* y) {
  for (int i = 0; i < n; ++i) {
    y[i] = 0;
    for (int j = 0; j < n; ++j) {
      y[i] += matrix[i * n + j] * x[j];
    }
  }
}

#endif  // ALGORITHM_ENGINEERING_GEMV_H_