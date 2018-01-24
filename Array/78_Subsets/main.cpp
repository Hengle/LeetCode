#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(1, vector<int>());
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int n = ans.size();
            for (int j = 0; j < n; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> nums{1,2,3};

    auto ret = s.subsets(nums);
    for (auto i : ret) {
        if (i.size() == 0) {
            cout << "[ ]";
        }
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
