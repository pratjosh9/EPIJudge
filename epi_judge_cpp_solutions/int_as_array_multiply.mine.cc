#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> Multiply(vector<int> num1, vector<int> num2) {
  int m = num1.size(), n = num2.size();
  vector<int> result(m+n, 0);
  int sign = (num1[0] * num2[0] >= 0) ? 0 : 1; 
  num1[0] = abs(num1[0]);
  num2[0] = abs(num2[0]);
  for (int i = n-1; i >= 0; i--) {
    int k = m+i, carry = 0;
    for (int j = m-1; j >= 0; j--){
      result[k] += num2[i] * num1[j] + carry;
      carry = result[k] / 10;
      result[k] %= 10;
      k--;
    }
    while(carry){
      result[k] += carry;
      carry = result[k] / 10;
      result[k] %= 10;
      k--;
    }
  }
  int k = 0;
  for (;k < m+n && result[k] == 0; k++);
  if (k == m+n) {
    k--;
  } 
  result.erase(result.begin(), result.begin() + k);
  
  if (sign){
    result[0] = -result[0];
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
