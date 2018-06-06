#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int max = 0;
            int c = i;
            while(nums[c] >= 0) {
                int t = nums[c];
                nums[c] = -1;
                c = t;
                max++;
                cout << t << " ";
            }
            cout << endl;
            if (ans < max) ans = max;
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> nums{5,4,0,3,1,6,2};
    Solution s;
    cout << s.arrayNesting(nums);
    return 0;
}
