#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (nums[mid]< target ) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
        
    }
};
int main() {
    return 0;
}