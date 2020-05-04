#include "test_framework/generic_test.h"
long long Reverse(int x) {
  int sign = (x > 0) ? 1 : 0;
  long long tmp = 0; 
  x = abs(x);
  while (x) {
    tmp = tmp * 10 + x % 10;
    x /= 10;
  }
  return (sign == 1) ? tmp : -tmp;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
