#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> leftProfit(n, 0);
        int maxLeftPro = 0, minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < minPrice) minPrice = prices[i];
            else maxLeftPro = max(maxLeftPro, prices[i] - minPrice);
            leftProfit[i] = maxLeftPro;
        }
        int ans = leftProfit[n - 1];
        int maxRightPro = 0, maxPrice = prices[n -1];
        for (int i = n - 2; i >=0; --i) {
            if (prices[i] > maxPrice) maxPrice = prices[i];
            else maxRightPro = max(maxRightPro, maxRightPro - prices[i]);
            ans = max(ans, maxRightPro + leftProfit[i]);
        }
        return ans;
    }
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int max = 0;
//        int min = INT_MAX;
//        for (int i = 0; i < n; ++i) {
//            if (prices[i] < min) min = prices[i];
//            if (prices[i] - min > max) max = prices[i] - min;
//        }
//        return max;
//    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> nums{2,1,2,0,1};
    Solution s;
    cout << s.maxProfit(nums);
    return 0;
}
