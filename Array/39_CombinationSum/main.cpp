#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> ans;
        for (int i = 0; i <len; ++i) {
            findNums(candidates, target, ans, i);
        }
        return ans;
    }
    void findNums(vector<int> &candidates, int target, vector<int> &ans, int numCount) {

    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> nums{2,3,6,7};
    Solution s;
    auto ans = s.combinationSum(nums, 7);
    for (const auto &i: ans) {
        for (int j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
