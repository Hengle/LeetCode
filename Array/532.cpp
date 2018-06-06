#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      if (k < 0 || nums.size() < 2) {
          return 0;
      }
      unordered_map<int, int> map;
      for (auto i : nums) {
          map[i]++;
      }
      int ans = 0;
      for (const auto &kv : map) {
          if (k ==0) {
              if (kv.second >= 2) {
                  ans++;
              }
          } else {
              if (map.count(kv.first - k)) {
                  ans++;
              }
          }
      }
      return ans;
    }
};
int main() {
    return 0;
}