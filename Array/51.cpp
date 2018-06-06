#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    const char queue = 'Q';
    const char empty = '.';
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> pos(n, -1);
        calc(0, pos, ans);
        return ans;
    }

  private:
    void calc(int row, vector<int> &pos,
              vector<vector<string>> &ans)
    {
        int num = pos.size();
        if (row >= num )
        {
            string rowStr(num, empty);
            vector<string> map(num, rowStr);
            for (int i = 0; i < num; ++i)
            {
                map[i][pos[i]] = queue;
            }
            ans.push_back(map);
            return;
        }
        for (int i = 0; i < num; ++i)
        {
            if (canPlace(row, i, pos))
            {
                pos[row] = i;
                calc(row + 1, pos, ans);
                pos[row] = -1;
            }
        }
    }
    bool canPlace( int row, int column, const vector<int> &pos)
    {
        for (int i = 0; i < row; ++i)
        {
            if (column == pos[i] || abs(row - i) == abs(pos[i] - column))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    for (int i = 0; i < 16; ++i)
    {
        auto ansList = s.solveNQueens(i);
        cout << "queue " << i << " ans count " << ansList.size() << endl;
        int t = 0;
        // for (auto ans: ansList) {
        //     cout << "ans " << t << endl;
        //     t++;
        //     for (auto s : ans) {
        //         cout << s << endl;
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}