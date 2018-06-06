#include <QCoreApplication>
class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        int tmp = num;
        while(tmp) {
            tmp >>= 1;
            mask <<= 1;
        }
        return (mask -1) ^ num;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;
    printf("%d\n", s.findComplement(5));
    printf("%d\n", s.findComplement(2));
    return a.exec();
}
