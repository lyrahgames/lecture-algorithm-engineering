#include <chrono>
#include <iostream>
#include <sstream>

#include <util.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "usage: " << argv[0] << " <int n...>" << std::endl;
    std::cout << "This application computes the n.fibonacci number for all "
                 "positive integers n given in the list with different "
                 "algorithms. ";
    return -1;
  }

  int n;

  std::cout << "#table of fibonacci numbers:" << std::endl << std::endl;
  std::cout << "#number\t"
            << "recursive\t"
            << "linear\t\t"
            << "constant" << std::endl;
  std::cout << "#n\tf(n),time[s]\tf(n),time[s]\tf(n),time[s]" << std::endl
            << std::endl;

  for (int i = 1; i < argc; i++) {
    std::stringstream(argv[i]) >> n;

    const auto t0 = std::chrono::system_clock::now();
    const int fib_recursive = ae::fibonacci_num_recursive(n);
    const auto t1 = std::chrono::system_clock::now();
    const int fib_linear = ae::fibonacci_num_linear(n);
    const auto t2 = std::chrono::system_clock::now();
    const int fib_const = ae::fibonacci_num_const(n);
    const auto t3 = std::chrono::system_clock::now();

    const auto time_recursive = std::chrono::duration<double>(t1 - t0).count();
    const auto time_linear = std::chrono::duration<double>(t2 - t1).count();
    const auto time_const = std::chrono::duration<double>(t3 - t2).count();

    std::cout << n << "\t" << fib_recursive << "\t" << time_recursive << "\t"
              << fib_linear << "\t" << time_linear << "\t" << fib_const << "\t"
              << time_const << std::endl;
  }

  return 0;
}