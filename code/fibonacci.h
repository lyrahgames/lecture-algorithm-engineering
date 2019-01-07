#ifndef ALGORITHM_ENGINEERING_FIBONACCI_H_
#define ALGORITHM_ENGINEERING_FIBONACCI_H_

#include <stdexcept>

template <class Integer>
Integer fibonacci(Integer n) {
  if (n < 0)
    throw std::invalid_argument(
        "Given integer in function 'fibonacci' must be positive.");

  Integer tmp0 = 0;
  Integer tmp1 = 1;

  for (Integer i = 0; i < n; ++i) {
    tmp1 = tmp0 + tmp1;
    tmp0 = tmp1 - tmp0;
  }

  return tmp0;
}

#endif  // ALGORITHM_ENGINEERING_FIBONACCI_H_