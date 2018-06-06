
#include <QCoreApplication>

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        for (int i = 0; i < nums.size(); ++i)
            rank.push_back(i);
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});

        vector<string> ret(nums.size());
        for (int i = 3; i < nums.size(); ++i) {
            ret[rank[i]] = to_string(i + 1);
        }
        if (nums.size() > 0) ret[rank[0]] = "Gold Medal";
        if (nums.size() > 1) ret[rank[1]] = "Silver Medal";
        if (nums.size() > 2) ret[rank[2]] = "Bronze Medal";

        return ret;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    Solution s;
    vector<string> ret = s.findRelativeRanks(nums);
    for (auto i : ret) {
        cout << i;
    }
    return a.exec();
}
