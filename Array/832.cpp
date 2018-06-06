#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int w = A.size();
        for (int i = 0; i < w; ++i) {
            std::reverse(A[i].begin(), A[i].end());
            int h = A[i].size();
            for (int j = 0; j < h; ++j) {
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};
int main(int argc, char **argv)
{
    vector<vector<int>> grid{
       {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    Solution s;

    return 0;
}