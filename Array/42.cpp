#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int total = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < maxLeft) {
                    total += (maxLeft - height[l]);
                } else {
                    maxLeft = height[l];
                }
                l++;
            } else {
                if ( height[ r ] < maxRight ) {
                    total += ( maxRight - height[ r ] );
                    
                } else {
                    maxRight = height[ r ];
                }
                r--;
            }
        }
        return total;
    }
};
int main()
{
    Solution s;
    vector<int> v { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << s.trap(v) << endl;
    return 0;
}
