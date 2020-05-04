#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  int sz = sizeof(x) * 8;
  while (sz > 1) {
    sz >>= 1;
    x ^= (x >> sz);
  }
  return x & 0x1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
