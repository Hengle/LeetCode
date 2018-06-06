#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        int i;
        for (i = 1; i < S.length(); ++i)
        {
            if (S[i] != S[i - 1])
            {
                end = i - 1;
                if (3 <= (end - start + 1))
                {
                    vector<int> pair;
                    pair.push_back(start);
                    pair.push_back(end);
                    ans.push_back(pair);
                }
                start = i;
            }
        }
        end = i - 1;
        if (3 <= (end - start + 1))
        {
            vector<int> pair;
            pair.push_back(start);
            pair.push_back(end);
            ans.push_back(pair);
        }
        return ans;
    }
};
int main()
{
    string s("abcdddeeeeaabbbcd");
    Solution slo;
    auto ans = slo.largeGroupPositions(s);
    for (const auto & v : ans) {
        for (auto i : v) {
            cout << " " << i; 
        }
        cout << endl;
    }
    return 0;
}