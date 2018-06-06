#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    return 0;
}
