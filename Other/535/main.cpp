#include <QCoreApplication>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
private:
    std::vector<string> mList;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mList.push_back(longUrl);
        stringstream ss;
        ss << mList.size() - 1;
        return ss.str();
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        stringstream ss;
        ss << shortUrl;
        int index;
        ss >> index;
        return index < mList.size() ? mList.at(index) : "";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
