#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  //   int minSubArrayLen(int s, vector<int> &nums) {
  //     int n = nums.size();
  //     if (n <= 0) {
  //       return 0;
  //     }

  //     vector<int> sum(n, 0);
  //     sum[0] = nums[0];
  //     for (int i = 1; i < n; ++i) {
  //       sum[i] = sum[i - 1] + nums[i];
  //     }

  //     int ans = INT_MAX;
  //     for (int i = 0; i < n; ++i) {
  //       for (int j = i; j < n; ++j) {
  //         int su = sum[j] - sum[i] + nums[i];
  //         if (su >= s) {
  //           ans = min(ans, j - i + 1);
  //           break;
  //         }
  //       }
  //     }
  //     return (ans != INT_MAX) ? ans : 0;
  //   }
  int minSubArrayLen(int s, vector<int> &nums) {
    int n = nums.size();
    if (n <= 0) {
      return 0;
    }
    vector<int> sums(n);
    sums[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + nums[i];
    }
    
    return 0;
  }
};

int main() {
  vector<int> v{1, 2, 3, 4, 5};
  Solution s;
  cout << s.minSubArrayLen(15, v) << endl;
  return 0;
}