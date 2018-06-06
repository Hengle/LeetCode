#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;
class Solution {
public:
    //123
    // int maxProfit(vector<int>& prices) {
    //     int lowestPrice1 = INT_MAX;
    //     int lowestPrice2 = INT_MAX;
//        int maxProfit1 = 0;
//        int maxProfit2 = 0;
//        for (auto i : prices) {
//            lowestPrice2 = max(min(lowestPrice1, i));
//            lowestPrice1 = min(lowestPrice1, i);
//        }
    //     return 0;
    // }


    //121 O(n)
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

    //121 general O(n^2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int max=0;
    //     for (int i = 0; i < n - 1; ++i) {
    //         for (int j = i + 1; j < n; ++j) {
    //             if (prices[j] - prices[i] > max) {
    //                 max = prices[j] - prices[i];
    //             } 
    //         }
    //     }
    //     return max;
    // }
    //122
    int maxProfit(vector<int>& prices) {
        
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> nums{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(nums);
    return 0;
}
