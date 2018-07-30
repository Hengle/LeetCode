#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        unordered_map<int, int> m;
        for (auto a : A) {
            for (auto b : B) {
                ++m[a + b];
            }
        }
        int ans = 0;
        for (auto c : C) {
            for (auto d : D) {
                auto it = m.find(-c - d);
                if (it != m.end()) {
                    ans += it->second;
                }
                // ans += m[-c - d];
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}