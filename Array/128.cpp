#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() < 1)
            return 0;
        int len = nums.size();
        map<int, int> mp;
        for (int i = 0; i < len; ++i) {
            mp[nums[i]] = i;
        }
        int maxLen = 1;
        int countNum = 1;
        int targetValue;
        auto it = mp.begin();
        while (it != mp.end()) {
            targetValue = (*it).first + 1;
            if (mp.count(targetValue)) {
                countNum++;
                ++it;
                continue;
            }
            if (countNum > maxLen) {
                maxLen = countNum;
            }
            countNum = 1;
            ++it;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    vector<int> nums { 1, 100, 2, 3, 4, 7 };
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}