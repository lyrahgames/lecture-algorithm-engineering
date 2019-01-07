#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>

#include <util.h>

template <class RNG>
void init_urand_vecf(RNG& rng, ae::vectorf& v) {
  std::uniform_real_distribution<> dis;
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    v[i] = dis(rng);
  }
}

template <class RNG>
void init_urand_matf(RNG& rng, ae::matrixf& m) {
  init_urand_vecf(rng, m.vdata());
}

int main(int argc, char const* argv[]) {
  using namespace std;
  using chrono::system_clock;
  using chrono::duration;

  if (argc != 3) {
    cout << "usage: " << argv[0] << " [int dimension] [int iterations]" << endl;
    return -1;
  }

  const int dim = atoi(argv[1]);
  assert(dim > 0);
  const int it = atoi(argv[2]);
  assert(it > 0);

  mt19937 rng(random_device{}());

  ae::matrixf m(dim, dim);
  init_urand_matf(rng, m);

  ae::vectorf v1(dim), v2(dim);
  init_urand_vecf(rng, v1);

  cout << "generated matrix: M" << endl << m << endl;
  cout << "generated vector: v" << endl;
  cout << v1 << endl << endl;

  const auto start = system_clock::now();

  for (int i = 0; i < it; i++) {
    v2 = m * v1;
    v1 = v2;
  }

  const auto end = system_clock::now();

  cout << "result: M^" << it << " v" << endl;
  cout << v2 << endl << endl;

  cout << "computing time: " << duration<double>(end - start).count() << " s"
       << endl;

  return 0;
}