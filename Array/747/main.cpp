#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;

        int maxOne = INT_MIN, maxTwo = INT_MIN;
        int maxOnePos = 0;
        for (int i = 0; i < len; ++i) {
            if (maxOne < nums[i]) {
                if (maxOne > maxTwo) {
                    maxTwo = maxOne;
                }
                maxOnePos = i;
                maxOne = nums[i];
            } else if (maxTwo < nums[i]) {
                maxTwo = nums[i];
            }
        }
        if (maxTwo * 2 > maxOne)
            return -1;
        else
            return maxOnePos;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> data{1,2,3,4};
    auto ret = s.dominantIndex(data);
    cout << ret << endl;
    return 0;
}
