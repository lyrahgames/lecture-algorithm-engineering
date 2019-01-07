#include "fibonacci_num.h"

namespace algorithm_engineering {

int fibonacci_num_recursive(int n) {
  assert(n >= 0);

  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  return fibonacci_num_recursive(n - 1) + fibonacci_num_recursive(n - 2);
}

int fibonacci_num_linear(int n) {
  assert(n >= 0);

  if (n == 0) return 0;

  std::vector<int> fibonacci_seq(n + 1);
  fibonacci_seq[0] = 0;
  fibonacci_seq[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibonacci_seq[i] = fibonacci_seq[i - 1] + fibonacci_seq[i - 2];
  }

  return fibonacci_seq[n];
}

int fibonacci_num_const(int n) {
  assert(n >= 0);

  int tmp0 = 0;
  int tmp1 = 1;

  for (int i = 1; i <= n; i++) {
    tmp1 = tmp1 + tmp0;
    tmp0 = tmp1 - tmp0;
  }

  return tmp0;
}

}  // algorithm_engineering