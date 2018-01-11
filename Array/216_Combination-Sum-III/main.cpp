#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curAns;
        findNums(n, ans, curAns, 1, k);

        return ans;
    }
private:
    void findNums(int n, vector<vector<int>> &ans, vector<int> curAns, int begin, int k) {
        if (n == 0) {
            ans.push_back(curAns);
            return;
        } else if (k == 0) {
            return;
        }
        for (int i = begin; i <= 9; ++i) {
//            bool hasContains = false;
//            for (int j = 0; j < curAns.size(); ++j) {
//                if (curAns[j] == i) {
//                    hasContains = true;
//                    break;
//                }
//            }
//            if (hasContains) continue;
            if (i * k + k * (k - 1) / 2 > n) {
                break;
            }
            curAns.push_back(i);
            findNums( n - i, ans, curAns, i + 1, k - 1);
            curAns.pop_back();
        }
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    auto ans = s.combinationSum3(3, 9);
    for (const auto &i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
