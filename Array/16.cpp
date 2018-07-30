#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        int m = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int l, r, s;

        for (int i = 0; i < n; ++i) {
            l = i + 1;
            r = n - 1;
            while (l < r) {
                s = nums[i] + nums[l] + nums[r];
                if (s < target) {
                    if (abs(s - target) < abs(m - target)) {
                        m = s;
                    }
                    l++;
                } else if (s > target) {
                    if (abs(s - target) < abs(m - target)) {
                        m = s;
                    }
                    r--;
                } else {
                    return target;
                }
            }
        }
        return m;
    }
};
int main()
{
    return 0;
}