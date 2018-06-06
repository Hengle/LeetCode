#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k && i - k - 1 < nums.size()) {
                window.erase(nums[i -k - 1]);
            }            
            auto pos = window.lower_bound((long long) nums[i] - t);
            if (pos != window.cend() && *pos - nums[i] <= t) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> v{
        1,2,3,1
    };
    cout << s.containsNearbyAlmostDuplicate(v, 3, 0) << endl;
    return 0;
}