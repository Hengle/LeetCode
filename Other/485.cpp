#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur++;
                max = cur > max ? cur : max;
            } else {
                cur = 0;
            }
        }
        return max;
    }
};
int main(int argc, char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    Solution s;
    cout << s.findMaxConsecutiveOnes(nums);
    return 0;
}
