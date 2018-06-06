#include <QCoreApplication>

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUpperA(const char & c) { return 'A' <= c && c <='Z';}
    bool isLowA(const char & c) { return 'a' <= c && c <='z';}
    bool detectCapitalUse(string word) {
        bool ret = true;
        if (word.length() > 1) {
            bool firstIsUpper = isUpperA(word[0]);
            if (firstIsUpper) {
                bool allUpper = true;
                for (int i = 1; i < word.length() ; i++) {
                    if (isLowA(word[i])) {
                        allUpper = false;
                        break;
                    }
                }
                if (allUpper)
                    return true;

                bool otherAllLow = true;
                for (int i = 1; i < word.length(); i++) {
                    if (isUpperA(word[i])) {
                        otherAllLow = false;
                        break;
                    }
                }
                if (otherAllLow)
                    return true;
                else
                    return false;
            } else {
                bool allLow = true;
                for (int i = 1; i < word.length(); i++) {
                    if (isUpperA(word[i])) {
                        allLow = false;
                        break;
                    }
                }
                if (allLow) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;
    cout << (s.detectCapitalUse("USA") ? ("true") : ("false"))<< endl;
    cout << (s.detectCapitalUse("FlaG") ? ("true") : ("false"))<<endl;
    cout << (s.detectCapitalUse("leetcode") ? ("true") : ("false"))<< endl;
    cout << (s.detectCapitalUse("ggg") ? ("true") : ("false"))<< endl;
    cout << (s.detectCapitalUse("Z") ? ("true") : ("false"))<< endl;
    return a.exec();
}
