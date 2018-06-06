#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 1);
    for (int row = 1; row <= rowIndex / 2; ++row) {
      ans[rowIndex - row] = ans[row] =
          long(ans[row - 1]) * (rowIndex - row + 1) / row;
    }
    return ans;
  }
};
int main(int argc, char **argv) {
  int n = 5;
  if (argc == 2) {
    n = atoi(argv[1]);
  }
  Solution s;
  auto ans = s.getRow(n);

  for (auto v : ans) {
    cout << v << " ";
  }

  cout << endl;
  return 0;
}