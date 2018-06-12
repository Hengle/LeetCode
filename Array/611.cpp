#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i > 0; --i) {
            int l = 0;
             int r = i - 1;
             while (l < r) {
                 if (nums[l] + nums[r] > nums[i]) {
                     count += r - l;
                     r--;
                 } else {
                     l++;
                 }
             }
        }
        return count;
    }
    // int triangleNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     sort(nums.begin(), nums.end());
        
    //     int ad;
    //     int de;
    //     int i = 0; 
    //     while (i < n && nums[i] == 0 ) i++;
    //     for (; i < n - 2; ++i) {
    //         for (int j = i + 1; j < n - 1; ++j) {
    //             ad = nums[i] + nums[j];
    //             de = nums[i] - nums[j];
    //             int k = j + 1;
    //             while (k < n && ad <= nums[k]) {
    //                 k++;
    //             }
    //             while (k < n && ad > nums[k] && de < nums[k]) {
    //                 k++;
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
};
int main() {
    Solution s;
    vector<int> v {2, 2, 3, 4};
    cout << s.triangleNumber(v) << endl;

}