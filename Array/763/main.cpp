#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        vector<int> ans;
        vector<int> lastAppear(26, -1);
        for (int i = 0; i < len; ++i) {
            lastAppear[S[i] - 'a'] = max(i, lastAppear[S[i] - 'a']);
        }
        int start = 0;
        int end = lastAppear[S[0] - 'a'];
        int curLastAppear = 0;
        for (int i = 0; i < len; ++i) {
            curLastAppear = lastAppear[S[i] - 'a'];
            end = max(end, curLastAppear);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution sln;
    string s = "ababcbacadefegdehijhklij";
    auto ans = sln.partitionLabels(s);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
