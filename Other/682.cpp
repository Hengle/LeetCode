#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, score = 0;
        vector<int> datas;
        for (auto s: ops) {
            if (s == "C") {
                sum -= datas.back();
                datas.pop_back();
                continue;
            } else if (s == "+") {
                score = datas[datas.size() - 1] + datas[datas.size() - 2];
                sum += score;
            } else if (s == "D"){
                score = datas.back() * 2;
                sum += score;
            } else {
                score = stoi(s);
                sum += score;
            }
            datas.push_back(score);
        }
        return sum;
    }
};
int main(int argc, char **argv) {
    Solution s;
    vector<string> ops;
    ops.push_back("5");
    ops .push_back("2");
    ops .push_back("C");
    ops .push_back("D");
    ops .push_back("+");

    cout << s.calPoints(ops) << endl;
    return 0;
}
