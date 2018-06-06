#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        size_t front = 0;
        for (int i = 0; i <= len; ++i) {
            if (i == len || s[i] == ' ') {
//                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }
        return s;
    }
//    string reverseWords(string s) {
//        string ret;
//        string tmp;
//        int len = s.length();
//        for (int i = 0; i < len; ++i) {
//            if (s[i] == ' ') {
//                for (int j = tmp.length() - 1; j >=0; --j) {
//                    ret.push_back(tmp[j]);
//                }
//                tmp.clear();
//                ret.push_back(' ');
//            } else {
//                tmp.push_back(s[i]);
//            }
//        }
//        for (int j = tmp.length() - 1; j >=0; --j) {
//            ret.push_back(tmp[j]);
//        }
//        return ret;
//    }
};


int main(int argc, char **argv) {
    Solution s;
    auto ret = s.reverseWords("Let's take LeetCode contest ");
    cout << ret << endl;
    return 0;
}
