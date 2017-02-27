#include <QCoreApplication>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> out;
        char s1[] = {"qwertyuiop"};
        char s2[] = {"asdfghjkl"};
        char s3[] = {"zxcvbnm"};
//        for (const auto &word : words) {
//            bool b1 = true, b2 = true
//            for (const auto &ch: word) {
//                if ()
//            }

//        }

        return out;
    }
    bool contains(const char & ch, const char *map, int len) {
        for (int i = 0; i < len; i++) {
            if (ch == map[i])
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
