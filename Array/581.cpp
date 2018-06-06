#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = -2;
        int minV = nums[n - 1];
        int maxV = nums[0];
        for (int i = 0; i < n; ++i) {
            maxV = max(maxV, nums[i]);
            if (nums[i] < maxV ) {
                right = i;
            }
            minV = min(minV, nums[n - 1 - i]);
            if (nums[n - i - 1 ] > minV) {
                left = n - i -1;
            }
        }
        return right - left + 1;
    }
};
int main() {

}