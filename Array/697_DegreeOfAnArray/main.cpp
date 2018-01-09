#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , pair<int,int>> datas;
        int  degree = INT_MIN, ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            auto &j = datas[nums[i]];
            j.second++;
            if (j.second == 1) {
                j.first = i;
            }
            if (j.second > degree) {
                degree = j.second;
                ans =  i - j.first + 1;
            } else if (j.second == degree) {
                if (i - j.first + 1 < ans) {
                    ans = i - j.first + 1;
                }
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> nums{2,1};
    cout << s.findShortestSubArray(nums);
    return 0;
}
