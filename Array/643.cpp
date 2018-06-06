#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long int maxSum = 0;
        long long int currentSum = 0;
        for (int i = 0; i < k; ++i) {
            maxSum += nums[i];
        }
        currentSum = maxSum;
        for (int i = k; i< n; ++i) {
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }
        return double(maxSum) / k;
    }
};

int main() {
    Solution s;
    vector<int> v{1,12,-5,-6,50,3};
    cout << s.findMaxAverage(v, 4) << endl;
    return 0;
}