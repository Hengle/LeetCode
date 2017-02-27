#include <QCoreApplication>
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum_xor = x ^ y;
        int count = 0;
        while (sum_xor) {
            count++;
            sum_xor = sum_xor & (sum_xor - 1);
        }
        return count;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;
    std::cout<<s.hammingDistance(1, 4);
    return a.exec();
}
