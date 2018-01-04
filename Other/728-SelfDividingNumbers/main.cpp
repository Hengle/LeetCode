#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (auto i = left; i <= right; ++i) {
            if (isSelfDividing(i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
private:
    bool isSelfDividing(int v) {
        int lastBit = 0;
        int t = v;
        while(t) {
            lastBit = t % 10;
            if (lastBit == 0) return false;
            if (v % lastBit != 0) return false;
            t = t / 10;
        }
        return true;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    auto v = s.selfDividingNumbers(1, 22);
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}
