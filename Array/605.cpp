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

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = flowerbed.size();
    int count = 0;
    for (int i = 0; i <= len - 1; ++i) {
      if (flowerbed[i] == 0) {
        if (i == 0) {
          if (flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            count++;
          }
        } else if (i == len - 1) {
          if (flowerbed[i - 1] == 0) {
            flowerbed[i] = 1;
            count++;
          }
        } else {
          if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            count++;
          }
        }
      }
    }

    return n <= count;
  }
};
int main() {

  Solution s;
  // vector<int> v{1, 0, 0, 0, 1};
//   vector<int> v{0, 0, 1, 0, 1};
  vector<int> v{1,0,0,0,1,0,0};

  cout << s.canPlaceFlowers(v, 2) << endl;
  return 0;
}
