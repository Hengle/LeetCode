#include <QCoreApplication>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, repeat = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0;j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    count++;
                    if (i !=0 && grid[i - 1][ j] == 1) repeat++;
                    if (j !=0 && grid[i][j -1] == 1) repeat++;
                }
            }
        }
        return 4 * count - repeat * 2;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> a1;
    a1.push_back(0);
    a1.push_back(1);
    a1.push_back(0);
    a1.push_back(0);

    vector<int> a2;
    a2.push_back(1);
    a2.push_back(1);
    a2.push_back(1);
    a2.push_back(0);


    vector<int> a3;
    a3.push_back(0);
    a3.push_back(1);
    a3.push_back(0);
    a3.push_back(0);


    vector<int> a4;
    a4.push_back(1);
    a4.push_back(1);
    a4.push_back(0);
    a4.push_back(0);

    vector<vector<int>> v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);

    Solution s;
    cout <<"ans:"<< s.islandPerimeter(v) << endl;
    return a.exec();
}
