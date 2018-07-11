#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words)
    {
        vector<vector<int>> alpha(26);
        for (int i = 0; i < S.length(); ++i) {
            alpha[S[i] - 'a'].push_back(i);
        }
        int count = 0;
        for (const auto& word : words) {
            int index = -1;
            bool found = true;
            for (char c : word) {
                int v = c - 'a';
                auto it = upper_bound(alpha[v].begin(), alpha[v].end(), index);
                if (it == alpha[v].end()) {
                    found = false;
                } else {
                    index = *it;
                }
            }
            if (found) {
                count++;
            }
        }
        return count;
    }
    // int numMatchingSubseq(string S, vector<string>& words)
    // {
    //     int count = 0;
    //     for (auto word : words) {
    //         int index = -1;
    //         for (int i = 0; i < word.length(); ++i) {
    //             index = index + 1;
    //             while (index < S.length() && S[index] != word[i])
    //                 index++;
    //             if (index >= S.length()) {
    //                 break;
    //             }
    //         }
    //         if (index < S.length()) {
    //             count++;
    //         }
    //     }
    //     return count;
    // }
};
int main()
{
    vector<string> ws{
        "a",
        "bb",
        "acd",
        "ace"
    };
    string S = "abcde";
    Solution s;
    cout << s.numMatchingSubseq(S, ws) << endl;
    return 0;
}