#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> ret;
        for (int i = 1; i <= n ; i++) {
            string t;
            if (i % 3 == 0)
                t.append("Fizz");
            if (i % 5 == 0)
                t.append("Buzz");
            if (t.empty())
                t.append(std::to_string(i));
            ret.push_back(t);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<string> ret = s.fizzBuzz(15);
    for (auto i:ret) {
        cout << i << endl;
    }
    return 0;
}
