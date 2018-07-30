#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> row;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 4)
            return ans;

        for (int i = 0; i < n - 3; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    auto s = nums[i] + nums[j] + nums[l] + nums[r];
                    if (s > target) {
                        --r;
                    } else if (s < target) {
                        ++l;
                    } else {
                        row.clear();
                        row.push_back(nums[i]);
                        row.push_back(nums[j]);
                        row.push_back(nums[l]);
                        row.push_back(nums[r]);
                        ans.push_back(row);
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                        while (l < r && nums[r + 1] == nums[r])
                            --r;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> v{ 1, 0, -1, 0, 2, -2 };
    Solution s;
    auto ans = s.fourSum(v, 0);
    for (auto row : ans) {
        for (auto i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}