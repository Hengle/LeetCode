#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for (auto i : nums) {
            if (count == 0) {
                res = i;
                count++;
            } else {
                res == i ? ++count : --count;
            }
        }
        return res;
    }
};
int main() {
    return 0;
}