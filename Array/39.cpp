#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curAns;
        findNums(candidates, target, ans, curAns, 0);

        return ans;
    }
private:
    void findNums(const vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> curAns, int index) {
        if (target == 0) {
            ans.push_back(curAns);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
            curAns.push_back(candidates[i]);
            findNums(candidates, target - candidates[i], ans, curAns, i);
            curAns.pop_back();
        }
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
