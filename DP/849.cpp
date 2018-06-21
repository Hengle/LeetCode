#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 0) {
                int l = i - 1;
                while (l >=0 && seats[l] == 0) {
                    l--;
                }
                int r = i + 1;
                while (r < n && seats[r] == 0) {
                    r++;
                }
                if (l >= 0 && r < n) {
                    ans = max(ans, min(i -l, r- i));
                } else if (l >= 0) {
                    ans = max(i - l, ans);
                } else {
                    ans = max(ans, r- i);
                }
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}