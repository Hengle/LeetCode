#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
      vector<vector<int>> subs;
      vector<int> sub;
      sort(nums.begin(), nums.end());
      subset(nums, subs, sub, 0);
      return subs;
  }
  void subset(vector<int> &nums, vector<vector<int>> &subs, vector<int> &sub, int k) {
      subs.push_back(sub);
      for (int i = k; i < nums.size(); ++i) {
          if (i!= k && nums[i] == nums[i -1] )continue;
          sub.push_back(nums[i]);
          subset(nums, subs, sub, i + 1);
          sub.pop_back();
      }
  }
};
int main() {
    Solution s;
    vector<int> v{1,2,2};
    auto ans = s.subsetsWithDup(v);
    for (auto row : ans) {
        for (auto i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
}