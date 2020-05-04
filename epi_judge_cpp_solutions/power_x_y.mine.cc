#include "test_framework/generic_test.h"
double Power(double x, int y) {
  // TODO - you fill in here.
  if (y < 0) {
    y = -y;
    x = 1.0 / x;
  }
  double res(1);
  while (y) {
    if (y & 1) {
      // If 1 is present at the current binary digit
      res *= x;
    }
    // Square x to reach next digit
    x *= x;
    // Shift y for next digit
    y >>= 1;
  }
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
