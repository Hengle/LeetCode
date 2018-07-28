#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if ( m < 1) 
            return 0;
        int n = obstacleGrid[0].size();
        if ( n < 1) 
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i - 1 >=0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if ( j -1 >= 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1] [n - 1];
    }
};
int main() {
    vector<vector<int>> v{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(v) << endl;
    return 0;
}