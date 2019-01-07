// A simple example to try  to get lots of Flops on
// Intel Xeon Phi co-processors.

#include <chrono>
#include <iostream>

#define SIZE_OF_ARRAY (1024 * 1024)
#define OUTER_COUNT 100000000
#define INNER_COUNT 128
// Floating pt ops per inner loop iteration
// TODO how many FLOPS does every iteration of the inner-loop execute
#define FLOPSPERCALC 2
// define some arrays
// TODO what is the meaning of these attributes?
float array_a[SIZE_OF_ARRAY] __attribute__((aligned(64)));
float array_b[SIZE_OF_ARRAY] __attribute__((aligned(64)));

int main(int argc, char *argv[]) {
  // initialize the compute arrays
  std::cout << "Initializing" << std::endl;
  // TODO initialize arrays array_a and array_b

  std::cout << "Starting Compute" << std::endl;

  // TODO measure the time of this outer loop
  float constexpr scaling_array_factor = 1.1f;
  // loop many times to really get lots of calculations

  const auto time0 = std::chrono::system_clock::now();

  for (int j = 0; j < OUTER_COUNT; ++j) {
    // scale 1st (array_a) array and add in the 2nd (array_b) array to the 2nd
    // array this is also known as the *axpy operation within the BLAS library
    for (int k = 0; k < INNER_COUNT; ++k) {
      // TODO compute axpy as described above on arrays array_a and array_b
      // using index k
      array_b[k] += scaling_array_factor * array_a[k];
    }
  }

  const auto time1 = std::chrono::system_clock::now();

  // # of gigaflops we just calculated
  // TODO calulate the number of Giga(!)-FLOPS the outer loop just executed
  const double gflops = FLOPSPERCALC * INNER_COUNT * OUTER_COUNT;

  // elasped time
  // TODO calculate elapsed seconds of outer loop
  const auto elapsed_seconds =
      std::chrono::duration<double>(time1 - time0).count();

  // Print the results
  if (elapsed_seconds > 0.0) {
    std::cout << "GFlops = " << gflops << ", Secs = " << elapsed_seconds
              << ", GFlops per sec = " << (gflops / elapsed_seconds)
              << std::endl;
  }
  return 0;
}
