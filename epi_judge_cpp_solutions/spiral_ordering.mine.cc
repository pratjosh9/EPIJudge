#include <vector>
#include <algorithm>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
  int n = square_matrix.size();
  vector<int> ordering;
  for (int i = 0; i < ceil(0.5 * (double)n); i++) {
    if (i == n - 1 - i) {
      ordering.emplace_back(square_matrix[i][i]);
      continue;
    }
    for (int j = i; j < n - 1 - i; j++) {
      ordering.emplace_back(square_matrix[i][j]);
    }
    for (int j = i; j < n - 1 - i; j++) {
      ordering.emplace_back(square_matrix[j][n-1-i]);
    }
    for (int j = n-1-i; j > i; j--) {
      ordering.emplace_back(square_matrix[n-1-i][j]);
    }
    for (int j = n-1-i; j > i; j--) {
      ordering.emplace_back(square_matrix[j][i]);
    }
  }
  return ordering;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
