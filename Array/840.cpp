#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
static auto x = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid.at(0).size();
        int count = 0;

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = 0; j < m - 2; ++j)
            {
                if (check(i, j, grid))
                {
                    count++;
                }
            }
        }
        return count;
    }

  private:
    bool check(int row, int col, const vector<vector<int>> &grid)
    {
        for (int k = 0; k < 9; ++k)
        {
            auto t = grid[row + k / 3][col + k % 3];
            if (t < 1 || t > 9)
            {
                return false;
            }
        }

        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] !=
            15)
        {
            return false;
        }
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] !=
            15)
        {
            return false;
        }
        if (grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1] !=
            15)
        {
            return false;
        }
        if (grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2] !=
            15)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> map{
        // {4, 3, 8, 4},
        // {9, 5, 1, 9},
        // {2, 7, 6, 2}

        //   {10, 3, 5},
        //   {1, 6, 11},
        //   {7, 9, 2}

        {5,6,4,4,9,5,2},
        {8,3,9,9,8,1,3},
        {6,2,5,7,4,7,6},
        {8,6,5,3,5,1,6},
        {2,4,3,3,6,3,8},
        {3,8,2,6,2,5,1},
        {5,2,9,7,9,7,4}

    };
    cout << s.numMagicSquaresInside(map) << endl;
    return 0;
}