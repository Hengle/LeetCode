#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for (auto i : S) {
            for (auto j : J) {
                if (i == j) ++count;
            }
        }
        return count;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution sln;
    string J = "aA";
    string S = "aAAzzzzz";
    auto ret = sln.numJewelsInStones(J, S);
    cout << ret << endl;
    return 0;
}
