#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                ret.push_back(k-- % 2 ? i++ : j--);
            } else {
                ret.push_back(i++);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    auto ret = s.constructArray(6, 4);
    for (auto i : ret) {
        cout << i << endl;
    }
    return 0;
}
