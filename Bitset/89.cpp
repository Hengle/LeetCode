#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> grayCode(int n) {
    bitset<32> bits;
    vector<int> ans;
    calc(ans, bits, n);
    return ans;
  }
  void calc(vector<int> &ans, bitset<32> &bits, int k) {
    if (k == 0) {
      ans.push_back(bits.to_ulong());
    } else {
      calc(ans, bits, k - 1);
      bits.flip(k - 1);
      calc(ans, bits, k - 1);
    }
  }
};
int main() {
  Solution s;
  auto ans = s.grayCode(2);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}