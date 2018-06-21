#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const auto inf = std::numeric_limits<int>::infinity();
        int left = 0;
        int right = nums.size();
        int m;
        int ret = -1;
        
        while (left < right) {
            // m = (left + right) / 2; //可能溢出
            m = left + (right - left) / 2;
            if (nums[m] < target) {
                left = m + 1;
            } else if (nums[m] > target){
                right = m;
            } else {
                ret = m;
                break;
            }
        }
        return ret;

    }
};
int main() {
    vector<int> v{1,2,3,4,5,6,7,8};
    Solution s;
    cout << s.search(v, 5) << endl;
    return 0;
}