#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> row;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j, k;
        for (int i = 0; i < n - 2; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                j = i + 1;
                k = n - 1;
                while (j < k) {
                    row.clear();
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        row.push_back(nums[i]);
                        row.push_back(nums[j]);
                        row.push_back(nums[k]);
                        ans.push_back(row);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            ++j;
                        while (j < k && nums[k + 1] == nums[k])
                            --k;
                    } else if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> v{ -1, 0, 1, 2, -1, -4 };
    Solution s;
    auto ans = s.threeSum(v);
    for (auto row : ans) {
        for (auto i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}