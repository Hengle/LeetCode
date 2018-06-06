#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int row = 0; row < numRows; ++row) {
            if (row == 0)  {
                ans[row].push_back(1);
            } else {
                ans[row].push_back(1);
                for (int column = 0; column < row - 1; ++column) {
                    ans[row].push_back(ans[row - 1][column] + ans[row - 1][column + 1]);
                }
                ans[row].push_back(1);
            }
        }
        return ans;
    }
};
int main(int argc, char **argv)
{
    int n = 5;
    if (argc == 2)
    {
        n = atoi(argv[1]);
    }
    Solution s;
    auto ans = s.generate(n);

    for (auto row : ans)
    {
        for (auto v : row)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}