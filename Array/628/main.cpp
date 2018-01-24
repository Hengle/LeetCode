#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
//    int maximumProduct(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int len = nums.size();
//        if (nums[1] > 0 || nums[len - 1] < 0) {
//            return nums[len - 3] * nums[len - 2] * nums[len - 1];
//        } else {
//            return max(nums[len - 3] * nums[len - 2] * nums[len - 1], nums[0] * nums[1] * nums[len - 1]);
//        }
//    }
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (auto n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
            if ( n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        return max(max1 * min1 * min2, max1 * max2 * max3);
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    return 0;
}
