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
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    if (n < 1)
      return -1;

    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += nums[i];
    }
    int left = 0;
    for (int i = 0; i < n; ++i) {
        if (left == sum) {
            return i;
        } else {
            left += nums[i];
            sum -= nums[i + 1];
        }
    }
    return -1;
  }
};
int main() {
    Solution s;
    vector<int> v{1,7,3,6,5,6};
    cout << s.pivotIndex(v) << endl;
    return 0;
}