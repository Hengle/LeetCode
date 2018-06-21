#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        
        int n = A.size();
        
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            ans += right - left;
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> v {2,1,4,3};
    cout << s.numSubarrayBoundedMax(v, 2, 3) << endl;
    return 0;
}