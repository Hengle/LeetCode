#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
      if (matrix.empty()) {
          return {};
      }
      int m = matrix.size();
      int n = matrix[0].size();
      vector<int> spiral(m * n);
      int u = 0;
      int d = m - 1;
      int l = 0;
      int r = n - 1;
      int k = 0;
      while (true) {
          for (int col = l; col <= r; col++) {
              spiral[k] = matrix[u][col];
              ++k;
          }
          ++u;
          if (u > d) break;
          for (int row = u; row <= d; row ++) {
              spiral[k] = matrix[row][r];
              ++k;
          }
          --r;
          if (r < l) break;

          for (int col = r; col >= l; col--) {
              spiral[k] = matrix[d] [col];
              ++k;
          }
          --d;
          if (d < u) break;

          for (int row = d; row >= u; row--) {
              spiral[k] = matrix[row] [l];
              ++k;
          }
          ++l;
          if (l > r) break;
      } 
      return spiral;
  }
};
int main() {
  Solution s;
  vector<vector<int>> v{
      {1,2,3},
      {4,5,6},
      {7,8,9}
  };
  auto ans = s.spiralOrder(v);
  for (auto v : ans) {
      cout << v << " ";
  }
  cout << endl;
  return 0;
}