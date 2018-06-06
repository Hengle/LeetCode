#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        int i ;
        for ( i = 0; i < s.size(); ++i) {
            ret ^= s[i] ^ t[i];
        }
        return (ret ^ t[i]);
    }
};
int main(int argc, char *argv[])
{
    string s("a");
    string t("aa");
    Solution so;
    char p = so.findTheDifference(s, t);
    cout << p;
    return 0;
}
