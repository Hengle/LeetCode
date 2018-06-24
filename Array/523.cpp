#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int lastSum =0;
        unordered_set<int> set;
        for (auto & i : nums) {
            lastSum = sum;
            sum += i;
            if (k) 
                sum %= k;
            if (set.count(sum)) {
                cout << i << endl;
                return true;
            }
            set.insert(lastSum);
        }
        return false;
    }
};
// [23, 2, 6, 4, 7] k = 6
//set       0   5   1   
//lastSum   0   5   1   1
// sum      5   1   1   5
int main() {
    Solution s;
    vector<int> v{23,2,6,4,7};
    s.checkSubarraySum(v, 6);

    return 0;
}