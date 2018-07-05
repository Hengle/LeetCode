#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix.at(0).size();
        int col0 = 1;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j > 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
int main()
{
    // vector<vector<int>> v{
    //     { 1, 1, 1 },
    //     { 1, 0, 1 },
    //     { 1, 1, 1 }
    // };
    vector<vector<int>> v{
        { 0, 1, 2, 0 },
        { 3, 4, 5, 2 },
        { 1, 3, 1, 5 }
    };
    Solution s;
    s.setZeroes(v);

    for (auto row : v) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}