#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  double maxProfit(0), rightMax = prices.back();
  for (int i = prices.size()-2; i >= 0; i--) {
    maxProfit = std::max(maxProfit, rightMax - prices[i]);
    rightMax = std::max(rightMax, prices[i]);
  }
  return maxProfit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}