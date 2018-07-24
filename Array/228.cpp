#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n < 1) {
            return ans;
        }
        int left = 0;
        int right = left;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i -1] != 1) {
                if (left == right) {
                    ans.push_back(to_string(nums[left]));
                } else {
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
                right = left = i;
            } else {
                right = i;
            }
        }
        if (left == right) {
            ans.push_back(to_string(nums[left]));
        } else {
            ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }    
        return ans;    
    }
};
int main() {
    vector<int> v{0,2,3,4,6,8,9};
    // vector<int> v{0,1,2,4,5,7};
    Solution s;
    auto ans = s.summaryRanges(v);
    for (auto str: ans) {
        cout << str << endl;
    }
    return 0;
}