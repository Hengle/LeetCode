#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid.at(0).size();
        vector<int> skyLineLeft(w, 0);
        vector<int> skyLineTop(w, 0);

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid.at(i).at(j) > skyLineLeft.at(i))
                {
                    skyLineLeft[i] = grid.at(i).at(j);
                }
                if (grid[j][i] > skyLineTop[i])
                {
                    skyLineTop[i] = grid.at(j).at(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                ans += min(skyLineTop[j], skyLineLeft[i]) -grid[i][j];
            }
        }

        // for (auto i : skyLineLeft)
        // {
        //     cout << "left " << i << endl;
        // }
        // for (auto i : skyLineTop)
        // {
        //     cout << "top " << i << endl;
        // }
        return ans;
    }
};
int main(int argc, char **argv)
{
    vector<vector<int>> grid{
        {3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    Solution s;
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}