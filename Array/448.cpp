#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (auto i: nums) {
            int v = abs(i) - 1;
            if (nums[v] > 0) {
                nums[v] = -nums[v];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                ret.push_back(i + 1);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
