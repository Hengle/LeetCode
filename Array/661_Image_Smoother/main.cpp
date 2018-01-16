#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int len = M.size();
        int width = M[0].size();
        vector<vector<int>> ans(len, vector<int>(width, 0));
        vector<int> offX{-1,  0, 1, -1, 0, 1, -1, 0, 1};
        vector<int> offY{-1, -1, -1, 0, 0, 0,  1, 1, 1};
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                int sum = 0, count = 0;
                for (int k = 0; k < offX.size(); ++k) {
                    int px = i + offX[k];
                    int py = j + offY[k];
                    if (px < 0 || px >= len || py < 0 || py >= width) continue;
                    count++;
                    sum += M[i + offX[k]][j + offY[k]];
                }
                if (count > 0) {
                    ans[i][j] = floor(sum / count);
                }
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    vector<vector<int>> m{
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    Solution s;
    auto ans = s.imageSmoother(m);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
