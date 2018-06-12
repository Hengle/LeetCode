#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int t;
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

int main() {
  // vector<vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> m{{1,2,3,4,}, {5,6,7,8}, {9, 10, 11, 12}, {13,14,15,16}};
  Solution s;
  s.rotate(m);

  for (auto r : m) {
    for (auto i : r) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}