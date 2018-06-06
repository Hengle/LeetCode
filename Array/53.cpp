#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
  // //  linear
  // int maxSubArray(vector<int> &nums)
  // {
  //   int n = nums.size();
  //   int sum = 0;
  //   int max = nums[0];
  //   for (auto i : nums)
  //   {
  //     sum += i;
  //     if (sum > max)
  //     {
  //       max = sum;
  //     }
  //     if (sum < 0)
  //       sum = 0;
  //   }
  //   return max;
  // }

  //DP
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> sums (n, 0);
    
    int m = nums[0];
    sums[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
      sums[i] = max(nums[i], sums[i - 1] + nums[i]);
      m = max(m, sums[i]);
    }
    return m;
  }
};
int main()
{
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution s;
  cout << s.maxSubArray(nums) << endl;
  return 0;
}