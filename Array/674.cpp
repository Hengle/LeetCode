#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0) {
      return 0;
    }
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
  }
};
int main() {
  Solution s;
  {
    vector<int> v{1, 3, 5, 4, 7};
    cout << s.findLengthOfLCIS(v) << endl;
  }
  {
    vector<int> v{2, 2, 2, 2, 2};
    cout << s.findLengthOfLCIS(v) << endl;
  }
}