#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> sum(n, 0);
    //     sum[0] = nums[0]; 
    //     for (int i = 1; i < n; ++i) {
    //         sum[i]  = sum[i - 1] + nums[i];
    //     }
    //     int count = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] == k) {
    //             count++;
    //         }
    //         for (int j = i + 1; j < n; ++j) {
    //             if (sum[j] - sum[i] + nums[i] == k) {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
    //     int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int sum;
    //     int count = 0;
    //     for (int i = 0; i < n; ++i) {
    //         sum = 0;
    //         for (int j = i ; j < n; ++j) {
    //             sum += nums[j];
    //             if (sum == k) {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
     int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> hash;
        int ans = 0;
        int sum = 0;
        hash[0] = 1;
        for (auto i : nums) {
            sum += i;
            ans += hash[sum - k];
            hash[sum]++;
        }
        return ans;
     }
};
int main() {
    Solution s;
    vector<int> v{1, 2, 3, 2, 1};
    cout << s.subarraySum(v, 3) << endl;
    return 0;
}