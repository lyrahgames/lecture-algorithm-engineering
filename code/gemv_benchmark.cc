#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "gemv.h"

int main(int argc, char** argv) {
  // read command line arguments
  if (3 != argc) {
    std::cout << "usage:\n"
              << argv[0] << " <dimension> <iterations>" << std::endl;
    return -1;
  }

  bool input_fail = false;
  int dimension;
  int iterations;

  std::stringstream dimension_argument{argv[1]};
  if (!(dimension_argument >> dimension) || !dimension_argument.eof()) {
    std::cerr << "Dimension could not be read from first argument."
              << std::endl;
    input_fail = true;
  }

  if (dimension <= 0) {
    std::cerr << "Dimension has to be a positive integer." << std::endl;
    input_fail = true;
  }

  std::stringstream iterations_argument{argv[2]};
  if (!(iterations_argument >> iterations) || !iterations_argument.eof()) {
    std::cerr << "Iterations could not be read from second argument."
              << std::endl;
    input_fail = true;
  }

  if (iterations <= 0) {
    std::cerr << "Iterations has to be a positive integer." << std::endl;
    input_fail = true;
  }

  if (input_fail) {
    std::cout << "usage:\n"
              << argv[0] << " <dimension> <iterations>" << std::endl;
    return -1;
  }

  std::vector<float> v(dimension);
  std::vector<float> m(dimension * dimension);
  std::vector<float> r(dimension);

  // random initialization
  std::mt19937 rng{std::random_device{}()};
  const std::uniform_real_distribution<float> distribution(-1, 1);
  const auto random_variable = std::bind(distribution, rng);
  std::generate(begin(v), end(v), random_variable);
  std::generate(begin(m), end(m), random_variable);

  // computation and time measuring
  const auto start_time = std::chrono::system_clock::now();
  for (int i = 0; i < iterations; ++i) {
    gemv(dimension, m.data(), v.data(), r.data());
  }
  const auto end_time = std::chrono::system_clock::now();

  const auto time =
      std::chrono::duration<double>(end_time - start_time).count();
  const double giga_flops = 1e-9 * 2 * dimension * dimension * iterations;

  std::cout << "flops = " << giga_flops << " Gflops" << std::endl;
  std::cout << "measured time = " << time << " s" << std::endl;
  std::cout << "performance = " << giga_flops / time << " Gflops/s"
            << std::endl;
}