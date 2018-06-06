#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto i : nums) {
            result ^= i;
        }
        return result;
    }
};
int main(int argc, char *argv[])
{
    vector<int> v;
    v.push_back(1);
    Solution s;
    auto t = s.singleNumber(v);
    cout << t << endl;

    return 0;
}
