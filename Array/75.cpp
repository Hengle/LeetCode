#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    // bubble sort
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = 0; i < n; ++i) {
    //         int index = i;
    //         for (int j = i + 1; j < n; ++j) {
    //             if (nums[j] < nums[index]) {
    //                 index = j;
    //             }
    //         }
    //         int t= nums[i];
    //         nums[i] = nums[index];
    //         nums[index] = t;
    //     }
    // }
    // void sortColors(vector<int> &nums) {
    //     unordered_map<int, int> m;
    //     for (auto i : nums) {
    //         m[i]++;
    //     }
    //     int index = 0;
    //     for (int i = 0; i < 3; ++i) {
    //         for (int j = 0; j < m[i]; j++) {
    //             nums[index] = i;
    //         }
    //     }
    // }
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return;
        int index0 = 0;
        int index2 = n - 1;
        for (int i = 0; i < index2; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[index0]);
                index0++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[index2]);
                i--;
                index2--;
            }
        }
    }
};
int main()
{
    Solution s;
    // vector<int> v{1,2,0, 0};
    vector<int> v{0, 2, 1, 2, 0, 2, 0, 1};
    s.sortColors(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}