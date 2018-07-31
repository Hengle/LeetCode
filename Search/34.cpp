#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 1)
        {
            return {-1, -1};
        }

        int l = 0;
        int r = n;
        int ret = -1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else if (nums[m] > target)
            {
                r = m;
            }
            else
            {
                ret = m;
                break;
            }
        }
        if (ret != -1)
        {
            int l = ret;
            while (l - 1 >= 0 && nums[l - 1] == nums[l])
                --l;

            int r = ret;
            while (r + 1 < n && nums[r + 1] == nums[r])
                ++r;
            return {l, r};
        }
        else
        {
            return {-1, -1};
        }
    }

    // int searchLeft(const vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     int l = 0;
    //     int r = n;
    //     int ret = -1;
    //     while (l < r)
    //     {
    //         int m = l + (r - l) / 2;
    //         if (nums[m] < target)
    //         {
    //             l = m + 1;
    //         }
    //         else if (nums[m] > target)
    //         {
    //             r = m;
    //         }
    //         else
    //         {
    //             ret = m;
    //             break;
    //         }
    //     }
    //     while (ret > 0 && nums[ret - 1] == nums[ret])
    //         --ret;
    //     return ret;
    // }
    // int searchRight(const vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     int l = 0;
    //     int r = n;
    //     int ret = -1;
    //     while (l < r)
    //     {
    //         int m = l + (r - l) / 2;
    //         if (nums[m] < target)
    //         {
    //             l = m + 1;
    //         }
    //         else if (nums[m] > target)
    //         {
    //             r = m;
    //         }
    //         else
    //         {
    //             ret = m;
    //             break;
    //         }
    //     }
    //     if (ret != -1)
    //     {
    //         while (ret < n - 1 && nums[ret + 1] == nums[ret])
    //             ++ret;
    //     }
    //     return ret;
    // }
    // vector<int> searchRange(vector<int> &nums, int target)
    // {
    //     if (nums.size() < 1)
    //     {
    //         return {-1, -1};
    //     }
    //     return {searchLeft(nums, target), searchRight(nums, target)};
    // }
    // vector<int> searchRange(vector<int> &nums, int target)
    // {
    //     if (find(nums.begin(), nums.end(), target) == nums.end())
    //     {
    //         return {-1, -1};
    //     }
    //     return {
    //         lower_bound(nums.begin(), nums.end(), target) - nums.begin(),
    //         prev(upper_bound(nums.begin(), nums.end(), target)) - nums.begin()};
    // }
};
int main()
{
}