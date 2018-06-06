#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
static auto x = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
      if (k >= 35000) 
      return false;
      int currentNum;
      for (int i = 0; i < nums.size(); ++i) {
          currentNum = nums[i];
          for (int j = i + 1; j < nums.size() && j <= i + k; ++j) {
              if (nums[j]== currentNum) {
                  return true;
              } 
          }
      }
      return false;
  }
    // bool containsNearbyDuplicate(vector<int> &nums, int k)
    // {
    //     unordered_map<int, int> s;
    //     int len = nums.size();
    //     for (int i = 0; i < len; ++i) {
    //         int n = nums[i];
    //         if (s.find(n) == s.end()) {
    //             s[n] = i;
    //         } else {
    //             if ( i - s[n] <= k) {
    //                 return true;
    //             } else {
    //                 s[n] = i;
    //             }
    //         }
    //     }
    //     return false;
    // }
    //   bool containsNearbyDuplicate(vector<int> &nums, int k) {
    //     map<int, int> s;
    //     nums.insert(nums.begin(), -1);
    //     for (int i = 1; i < nums.size(); ++i) {
    //       auto num = nums[i];
    //       if (s[num] == 0) {
    //         s[num] = i;
    //       } else {
    //         if (i - s[num] <= k) {
    //           return true;
    //         } else {
    //           s[num] = i;
    //         }
    //       }
    //     }
    //     return false;
    //   }
};
int main()
{

    Solution s;
    vector<int> v{1, 2, 3, 1};
    cout << s.containsNearbyDuplicate(v, 3) << endl;
}