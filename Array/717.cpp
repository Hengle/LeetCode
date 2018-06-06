#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ans = true;
        int n = bits.size();
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) break;
            if (bits[i] == 1) i++;
            if ((i + 1) > n -1) ans = false;
        }
        return ans;
    }
    //    bool isOneBitCharacter(vector<int>& bits) {
    //        int n = bits.size();
    //        int i = 0;
    //        bool isFirst = false;
    //        while(i < n) {
    //            if (bits[i] == 0) {
    //                isFirst = true;
    //                i++;
    //            } else {
    //                i+=2;
    //                isFirst = false;
    //            }
    //        }
    //        return isFirst;
    //    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    vector<int> bits{1,1,1,0};
    Solution s;
    cout << s.isOneBitCharacter(bits) << endl;
    return 0;
}
