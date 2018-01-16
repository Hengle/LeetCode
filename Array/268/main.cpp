#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (1 + len) * len / 2;
        int acc = 0;
        for (auto i : nums) {
            acc += i;
        }
        return sum - acc;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> num{45,35,38,13,12,23,48,15,44,21,43,26,6,37,1,19,22,3,11,32,4,16,28,49,29,36,33,8,9,39,46,17,41,7,2,5,27,20,40,34,30,25,47,0,31,42,24,10,14};
    Solution s;
    cout << s.missingNumber(num);
    return 0;
}
