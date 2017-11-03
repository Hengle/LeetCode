#include <QCoreApplication>
#include <string>
#include <QDebug>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char ch: moves) {
            switch(ch) {
            case 'U': {
                y--;
                break;
            }
            case 'D': {
                y++;
                break;
            }
            case 'L': {
                x--;
                break;
            }
            case 'R': {
                x++;
                break;
            }
            default:break;
            }
        }
        return  (x == 0 && y == 0 );
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Solution s;
    qWarning() << s.judgeCircle(string("DURDLDRRLL"));
    return a.exec();
}
