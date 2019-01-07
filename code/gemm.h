#ifndef ALGORITHM_ENGINEERING_GEMM_H_
#define ALGORITHM_ENGINEERING_GEMM_H_

template <class T>
void gemm(int n, const T* a, const T* b, T* c) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        c[i * n + j] += a[i * n + k] * b[k * n + j];
      }
    }
  }
}

#endif  // ALGORITHM_ENGINEERING_GEMM_H_