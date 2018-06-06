#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> a1{7, 9, 3, 4, 8, 4};
  vector<int> a2{8, 5, 6, 4, 5, 7};
  vector<int> c1{2, 2, 1, 2, 2, 1, 2};
  vector<int> c2{4, 2, 3, 1, 3, 4, 3};
  int n = a1.size();
  vector<int> S1(n, 0);
  vector<int> S2(n, 0);
  vector<int> l1(n, 0);
  vector<int> l2(n, 0);
  S1[0] = c1[0] + a1[0];
  S2[0] = c2[0] + a2[0];

  for (int i = 1; i < n; ++i) {
    S1[i] = min(S1[i - 1] + a1[i], S2[i - 1] + c1[i] + a1[i]);
    S2[i] = min(S2[i - 1] + a2[i], S1[i - 1] + c2[i] + a2[i]);
    if (S1[i - 1] + a1[i] < S2[i - 1] + c1[i] + a1[i]) {
        l1[i - 1] = 1;
    } else {
        l1[i - 1] = 2;
    }
    if (S2[i - 1] + a2[i] < S1[i - 1] + c2[i] + a2[i]) {
        l2[i - 1] = 2;
    } else {
        l2[i - 1] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
      cout << l1[i] << " " << l2[i] << endl;
  }
  cout << S1[n - 1] + c2[n] << endl;
  cout << S2[n - 1] + c1[n] << endl;
}