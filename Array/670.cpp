#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int maximumSwap(int num)
    {
        auto str = std::to_string(num);
        int last[10] = {0};
        int len = str.length();
        int max = num;
        
        for (int i = 0; i < len; ++i) {
            last[str[i] - '0'] = i;
        }        

        for (int i = 0; i < len - 1; ++i) {
            for (int d = 9; d > str[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};
int main(int argc, char** argv)
{
    if (argc != 2) {
        cout << "Usage:" << argv[0] << " number \n";
        exit(EXIT_FAILURE);
    }
    Solution s;
    cout << s.maximumSwap(atoi(argv[1])) << endl;
    return 0;
}
