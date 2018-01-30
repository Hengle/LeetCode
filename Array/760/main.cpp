#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> ans(len);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (B[j] >=0 && B[j] == A[i]) {
                    ans[i] = j;
                    B[j] = -B[j];
                    break;
                }
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    vector<int> A{12, 28, 46, 32, 50};
    vector<int> B{50, 12, 32, 46, 28};
    auto ans = s.anagramMappings(A, B);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
