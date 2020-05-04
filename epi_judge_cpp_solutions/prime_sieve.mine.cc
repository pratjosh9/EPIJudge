#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  vector<int> ans;
  if (n <= 1) return ans;
  vector<int> sieve(n+1, 0);
  for (int i = 2; i <= n; i++) {
    if (sieve[i] == 0) {
      ans.push_back(i);
      for (int j = 2*i; j <= n; j += i) {
        sieve[j] = 1;
      }
    }
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
