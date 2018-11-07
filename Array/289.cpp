#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int row = board.size();
        int col = board.at(0).size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int sum = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, row); ++I) {
                    for (int J = max(j - 1, 0); J < min(j + 2, col); ++J) {
                        sum += board[I][J] & 1;
                    }
                }
                if (sum == 3 || sum - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
    // void gameOfLife(vector<vector<int>>& board)
    // {
    //     int row = board.size();
    //     int col = board.at(0).size();
    //     vector<vector<int>> cp(row, vector<int>(col, 0));
    //     for (int i = 0; i < row; ++i) {

    //         for (int j = 0; j < col; ++j) {
    //             int sum = 0;

    //             if (i - 1 >= 0) {
    //                 if (j - 1 >= 0) {
    //                     sum += board[i - 1][j - 1];
    //                 }
    //                 sum += board[i - 1][j];
    //                 if (j + 1 < col) {
    //                     sum += board[i - 1][j + 1];
    //                 }
    //             }
    //             if (i + 1 < row) {
    //                 if (j - 1 >= 0) {
    //                     sum += board[i + 1][j - 1];
    //                 }
    //                 sum += board[i + 1][j];
    //                 if (j + 1 < col) {
    //                     sum += board[i + 1][j + 1];
    //                 }
    //             }
    //             if (j - 1 >= 0) {
    //                 sum += board[i][j - 1];
    //             }

    //             if (j + 1 < col) {
    //                 sum += board[i][j + 1];
    //             }

    //             if (board[i][j] == 1) {
    //                 if (sum == 2 || sum == 3) {
    //                     cp[i][j] = 1;
    //                 }
    //             } else {
    //                 if (sum == 3) {
    //                     cp[i][j] = 1;
    //                 }
    //             }
    //         }
    //     }
    //     swap(board, cp);
    // }
};
int main()
{
    vector<vector<int>> v{ { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 1 }, { 0, 0, 0 } };
    Solution s;
    cout << "before" << endl;
    for (auto row : v) {
        for (auto value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    s.gameOfLife(v);
    cout << "after" << endl;
    for (auto row : v) {
        for (auto value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}