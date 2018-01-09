#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>&nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int fromBegin = 1;
        int fromEnd = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] *= fromBegin;
            fromBegin *= nums[i];
            ans[n - i - 1] *= fromEnd;
            fromEnd *= nums[n - i - 1];
        }
        return ans;
    }
//    vector<int> productExceptSelf(vector<int>&nums) {
//        int n = nums.size();
//        vector<int> fromBegin(n), fromEnd(n), ans(n);
//        fromBegin[0] = 1;
//        fromEnd[0] = 1;
//        for (int i = 1; i < n; ++i) {
//            fromBegin[i] = nums[i - 1] * fromBegin[i - 1];
//            fromEnd[i] = nums[n - i] * fromEnd[i - 1];
//        }
//        for (int i = 0; i < n; ++i) {
//            ans[i] = fromBegin[i] * fromEnd[ n - i - 1];
//        }
//        return ans;
//    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> nums{1,2,3,4};
    auto ret = s.productExceptSelf(nums);
    for (auto i : ret) {
        cout << i << endl;
    }
    return 0;
}
