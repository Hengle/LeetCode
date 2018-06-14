#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> dirs = {
        {0, 1},  // right
        {1, 0},  // down
        {0, -1}, // left
        {-1, 0}  // up
    };
    int dir = 0;

    int x = 0;
    int y = 0;
    //当前方向应该前进的步数
    // current direction should walk step count
    int step = n - 1;
    //当前step使用次数
    // current step use count
    int stepCount = 0;
    //前进次数
    // walk count
    int count = 0;
    // first time walk
    bool firstStep = true;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 1; i <= n * n; ++i) {
      v[x][y] = i;
      x += dirs[dir][0];
      y += dirs[dir][1];
      count++;
      if (count >= step) { //前进次数达到step     walk count equal with step
        count = 0;         //重置前进计数         reset walk count
        stepCount++; //增加当前step使用次数  increase current step use count
        dir = (dir + 1) % 4; //切换下一个方向        change direction
        if (firstStep) { //第一次的时候step用3次，   first time, step should be
                         //use 3 times
          if (stepCount >= 3) {
            stepCount = 0;
            step--;
            firstStep = false;
          }
        } else if (stepCount >= 2) { //其它时候，step用2次 other time, step
                                     //should be use 2 times
          stepCount = 0;
          step--;
        }
      }
    }
    return v;
  }
};
int main() {
  Solution s;
  auto mat = s.generateMatrix(9);
  for (auto row : mat) {
    for (auto v : row) {
      printf("%3d ", v);
    }
    printf("\n");
  }
  return 0;
}