#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIdealPermutation(vector<int>& A)
    {
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i] - i) > 1)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    {
        vector<int> v{ 1, 0, 2 };
        cout << s.isIdealPermutation(v) << endl;
    }
    {
        vector<int> v{ 1, 2, 0 };
        cout << s.isIdealPermutation(v) << endl;
    }
    return 0;
}