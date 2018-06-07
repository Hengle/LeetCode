#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     k = k % nums.size();
    //     for (int i = 0; i < k; ++i) {
    //         nums.insert(nums.begin(), nums.back());
    //         nums.pop_back();
    //     }
    // }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> copy(k);
        for (int i = 0; i < k; ++i) {
            copy[i] = nums[n - k + i];
        }
        for (int i = n - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = copy[i];
        }
    } 
};
int main() {
    vector<int> v{1,2,3,4,5,6,7};
    Solution s;
    s.rotate(v, 3);
    return 0;
}