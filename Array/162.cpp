#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
int main() {
    Solution s;
    vector<int> v {1, 2, 1, 2, 3, 2};
    cout << s.findPeakElement(v) << endl;
    return 0;
}