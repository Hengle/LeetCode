#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int len = m + n - 1;
    --m;
    --n;
    while (m >= 0 && n >= 0) {
      if (nums1[m] > nums2[n]) {
        nums1[len] = nums1[m];
        len--;
        m--;
      } else {
        nums1[len] = nums2[n];
        len--;
        n--;
      }
    }
    while (n >= 0) {
      nums1[len] = nums2[n];
      len--;
      n--;
    }
  }
  // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  //     int len = m + n;
  //     vector<int> ans(len);
  //     int index1 = 0;
  //     int index2 = 0;
  //     for (int i = 0; i < len; ++i) {
  //         if (index1 >= m) {
  //             ans[i] = nums2[index2];
  //             index2++;
  //         } else if (index2 >= n) {
  //             ans[i] = nums1[index1];
  //             index1++;
  //         } else  if (nums1[index1] <= nums2[index2]) {
  //             ans[i] = nums1[index1];
  //             index1++;
  //         } else {
  //             ans[i] = nums2[index2];
  //             index2++;
  //         }
  //     }
  //     for (int i = 0; i < len; ++i) {
  //         nums1[i] = ans[i];
  //     }
  // }
};
int main() {
  vector<int> v1{1, 2, 3, 0, 0, 0};
  vector<int> v2{2, 5, 6};
  Solution s;
  s.merge(v1, 3, v2, 3);
  for (auto i : v1) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}