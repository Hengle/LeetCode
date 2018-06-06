#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int c =0 , i = a.size() - 1, j = b.size() - 1;
        while (i >=0 || j>= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            ret = char (c % 2 + '0') + ret;
            c /= 2;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
