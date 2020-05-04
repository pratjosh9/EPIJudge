#include <vector>
#include <utility>
#include "test_framework/generic_test.h"
using std::vector;

void ApplyPermutation(vector<int> perm, vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  int n = A.size();
  int numApplied = 0, curIdx = 0;
  vector<int> status(n, 0);
  while (numApplied < n) {
  	if (status[curIdx] == 1) ++curIdx;
  	else {
  		if (perm[curIdx] == curIdx) {
  			status[curIdx] = 1;
  			++curIdx;
  		} else {
  			int permVal = perm[curIdx];
  			std::swap(A[permVal], A[curIdx]);
  			std::swap(perm[permVal], perm[curIdx]);
  			status[permVal] = 1;
  		}
  		numApplied++;
  	}
  	curIdx %= n;
  }
  return;
}
vector<int> ApplyPermutationWrapper(const vector<int>& perm, vector<int> A) {
  ApplyPermutation(perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}