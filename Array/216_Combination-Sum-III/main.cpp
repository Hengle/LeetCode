#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
//        for (int i = 1; )
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    auto ans = s.combinationSum3(3, 7);
    for (const auto &i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
