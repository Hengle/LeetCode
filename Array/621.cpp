#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> s(26, 0);
        for (auto i : tasks) {
            s[i - 'A']++;
        }
        sort(s.begin(), s.end());
        int i = 25;
        while (i >=0 && s[i] == s[25]) i--;
        return max((int)tasks.size(), (s[25] - 1)* (n + 1) + (25 - i));
    }
};
int main() {
    return 0;
}