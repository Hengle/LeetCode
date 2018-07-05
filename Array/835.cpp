#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        vector<int> lA, lB;
        unordered_map<int, int> count;
        int N = A.size();
        for (int i = 0; i < N * N; ++i) {
            if (A[i / N][i % N] == 1) {
                lA.push_back(i / N * 100 + i % N);
            }
            if (B[i /N][i % N] == 1) {
                lB.push_back(i / N * 100 + i % N);
            }
        }
        for (auto i : lA) {
            for (auto j : lB) {
                count[i - j]++;
            }
        }
        int ans = 0;
        for (auto it : count) {
            ans = max(ans, it.second);
        }
        return ans;
    }

    
};
// class Solution {
// public:
//     int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
//     {
//         int m = A.size();
//         if (m <= 0)
//             return 0;
//         int n = A.at(0).size();

//         int maxAns = 0;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i == 0 && j == 0) {
//                     maxAns = max(maxAns, calcTranslate(A, B, i, j));
//                 } else {
//                     maxAns = max(maxAns, calcTranslate(A, B, i, j));
//                     maxAns = max(maxAns, calcTranslate(B, A, i, j));
//                 }
//             }
//         }
//         return maxAns;
//     }

//     int calcTranslate(vector<vector<int>>& A, vector<vector<int>>& B, int xOffset, int yOffset)
//     {
//         int m = A.size();
//         if (m <= 0)
//             return 0;
//         int n = A.at(0).size();
//         int avalidRow = m - xOffset;
//         int avalidCol = n - yOffset;
//         int ans = 0;

//         for (int i = 0; i < avalidRow; ++i) {
//             for (int j = 0; j < avalidCol; ++j) {
//                 ans += (A[xOffset + i][yOffset + j] == 1 && B[i][j] == 1);
//             }
//         }
//         return ans;
//     }
// };
int main()
{
    // vector<vector<int>> A{
    //     { 1, 1, 0 },
    //     { 0, 1, 0 },
    //     { 0, 1, 0 }
    // };
    // vector<vector<int>> B{
    //     { 0, 0, 0 },
    //     { 0, 1, 1 },
    //     { 0, 0, 1 }
    // };
    vector<vector<int>> A{
        { 1, 0 },
        { 0, 0 }
    };
    vector<vector<int>> B{
        { 0, 1 },
        { 1, 0 }
    };

    Solution s;
    cout << s.largestOverlap(A, B) << endl;
    return 0;
}