#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  // 121 O(n)
  //    int maxProfit(vector<int>& prices) {
  //        int n = prices.size();
  //        int max = 0;
  //        int min = INT_MAX;
  //        for (int i = 0; i < n; ++i) {
  //            if (prices[i] < min) min = prices[i];
  //            else if (prices[i] - min > max) max = prices[i] - min;
  //        }
  //        return max;
  //    }

  // 121 general O(n^2)
  // int maxProfit(vector<int>& prices) {
  //     int n = prices.size();
  //     int max=0;
  //     for (int i = 0; i < n - 1; ++i) {
  //         for (int j = i + 1; j < n; ++j) {
  //             if (prices[j] - prices[i] > max) {
  //                 max = prices[j] - prices[i];
  //             }
  //         }
  //     }
  //     return max;
  // }
  // 122
  // int maxProfit(vector<int>& prices) {
  //     int profit = 0;
  //     for (int i = 1; i < prices.size(); ++i) {
  //         if (prices[i] - prices[i - 1] > 0) {
  //             profit += prices[i] - prices[i - 1];
  //         }
  //     }
  //     return profit;
  // }

  // 123
  //   int maxProfit(vector<int> &prices) {
  //     int len = prices.size();

  //     int buy1 = INT_MAX;
  //     int buy2 = INT_MAX;
  //     int sell1 = 0;
  //     int sell2 = 0;

  //     for (int i = 0; i < len; ++i) {
  //         buy1 = min(prices[i],buy1);
  //         sell1 = max(sell1, prices[i] - buy1);
  //         buy2 = min(buy2, prices[i] - sell1);
  //         sell2 = max(sell2, prices[i] - buy2);

  //     }
  //     return sell2;
  //   }
  // 188
  int maxProfit(int k, vector<int> &prices) {
    int len = prices.size();
    if (k >= len / 2) {
      return quickSolve(prices);
    }
    vector<vector<int>> dp(k + 1, vector<int>(len));
    for (int i = 1; i <= k; ++i) {
      int m = -prices[0];
      for (int j = 1; j < len; ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + m);
        m = max(m, dp[i - 1][j - 1] - prices[j]);
      }
    }
    return dp[k][len - 1];
  }
  int quickSolve(vector<int> &prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] - prices[i - 1] > 0) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};
int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Solution s;
  //   {
  //     vector<int> nums{3, 3, 5, 0, 0, 3, 1, 4};
  //     cout << s.maxProfit(nums) << endl;
  //   }
  {
    vector<int> nums{3, 3, 6, 5, 0, 3};
    cout << s.maxProfit(2, nums) << endl;
  }
  return 0;
}
