#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        int product = 1.0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[left];
                left++;   
            }
            ans += i - left + 1;
        }
        return ans;
    }

};
int main() {
    vector<int> v{10, 5,2,6};

    Solution s;
    cout << s.numSubarrayProductLessThanK(v, 100) << endl;

    return 0;
}