#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
  public:

    // bool checkPossibility(vector<int> &nums)
    // {
    //     for (int i = 0; i < nums.size(); ++i) {
    //         auto oldN = nums[i];
    //         nums[i] = (i == 0 ? INT_MIN : nums[i - 1]);
    //         if (check(nums)) {
    //             return true;
    //         }
    //         nums[i] = oldN;
    //     }
    //     return false;
    // }
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        int p = -1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (p != -1) {
                    return false;
                }
                p = i - 1;
            }
        }
        return (p == -1 || p == 0 || p == len - 2 || nums[p - 1] <= nums[p + 1] ||  nums[p] <= nums[p + 2] );
    }

  private:
  bool check(const vector<int> &nums) {
      for (int i = 1; i < nums.size(); ++i) {
          if (nums[i] < nums[i - 1]) {
              return false;
          }
      }
      return true;
  }
};
int main()
{
    Solution s;
    {
        vector<int> v{4, 2, 3};
        cout << s.checkPossibility(v) << endl;
    }
        {
        vector<int> v{4, 2, 1};
        cout << s.checkPossibility(v) << endl;
    }
    return 0;
}