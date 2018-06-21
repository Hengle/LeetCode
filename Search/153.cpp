#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (nums[left] > nums[right]) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
int main()
{
    vector<int> v{4, 5, 6, 7, 8, 1, 2, 3};
    Solution s;
    cout << s.findMin(v) << endl;
    return 0;
}