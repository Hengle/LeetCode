#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void getQueueCount(int n) {
        count = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        calc(n, 0, 0, ans);
    }
    int getCount() {
        return count;
    }
private:
    int count = 0;
    void output(vector<vector<int>> &datas) {

        for (auto i : datas) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void calc(int num, int row, int column, vector<vector<int>> &datas) {
        if (row >= num || column >= num) {
            count++;
            cout <<"count:" << count << endl;
//            output(datas);
            return;
        }
        for (int i = 0; i < num; ++i) {
            if (canPlace(num, row, i, datas)) {
                datas[row][i] = 1;
                calc(num, row + 1, 0, datas);
                datas[row][i] = 0;
            }
        }
    }
    bool canPlace(int num,int row, int column, vector<vector<int>> &datas) {
        for (int i = 0; i < num; ++i) {
            if (i != column && datas[row][i] == 1 ) {
                return false;
            }
            if (i < row && datas[i][column] == 1) {
                return false;
            }
        }
        int x = row - 1, y = column - 1;
        while (x >= 0 && y >= 0) {
            if (datas[x][y] == 1) return false;
            x--;
            y--;
        }
        x = row - 1;
        y = column + 1;
        while (x >=0 && y < num) {
            if (datas[x][y] == 1) return false;
            x--;
            y++;
        }
        return true;
    }
};
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Solution s;
    for (int i = 1; i < 15; i++) {
        s.getQueueCount(i);
        cout << i << " " << s.getCount() << endl;;
    }
    cout << "over";
    return 0;
}
