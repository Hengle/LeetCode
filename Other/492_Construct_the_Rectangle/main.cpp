#include <QCoreApplication>

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        int a = floor(sqrt(area));
        int m = area % a;
        while(m && a > 0) {
            a--;
            m = area % a;
        }
        ret.push_back(area / a);
        ret.push_back(a);
        return ret;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;
    vector<int> ret;
    ret = s.constructRectangle(4);
    for (auto i: ret) {
        cout << i << endl;
    }
    return a.exec();
}
