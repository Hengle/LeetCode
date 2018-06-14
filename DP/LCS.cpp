#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  //最长公共子序列 不连续
  int lcs(const vector<int> &v1, const vector<int> &v2) {
    int n = v1.size();
    int m = v2.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (v1[i - 1] == v2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
  //最长公共子序列，连续
  int lcs_c(const vector<int> &v1, const vector<int> &v2) {
    int n = v1.size();
    int m = v2.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (v1[i - 1] == v2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
  //最长上升子序列
  int longestCommonSubSequence(const vector<int> &v) {
    int n = v.size();
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (dp[j] + 1 > dp[i] && v[j] < v[i]) {
          dp[i] = dp[j] + 1;
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> v1{1, 3, 4, 2, 3, 5, 6};
  vector<int> v2{3, 2, 5, 1, 2, 3, 5};
  cout << s.lcs(v1, v2) << endl;
  cout << s.lcs_c(v1, v2) << endl;
  cout << s.longestCommonSubSequence(v1) << endl;
  return 0;
}