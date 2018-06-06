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
            if (i == index || candidates[i] != candidates[i-1]) {
                curAns.push_back(candidates[i]);
                findNums(candidates, target - candidates[i], ans, curAns, i + 1);
                curAns.pop_back();
            }
        }
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> nums {10, 1, 2, 7, 6, 1, 5};
    auto ans = s.combinationSum(nums, 8);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
