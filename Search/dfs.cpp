#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using std::bitset;
using std::cout;
using std::endl;
using std::min;
using std::queue;
using std::vector;
class Solution {
    struct Point {
        int x = 0;
        int y = 0;
        Point () {}
        Point (int xValue, int yValue) : x (xValue), y (yValue) {}
        bool operator==(const Point &other) const {
            return x == other.x && y == other.y;
        }
        Point &operator+(const Point &other) {
            x += other.x;
            y += other.y;
            return *this;
        }
        Point clone () const {
            return { this->x, this->y };
        }
        bool inRange (const Point &start, const Point &end) const {
            if (x < start.x || x > end.x) {
                return false;
            }
            if (y < start.y || y > end.y) {
                return false;
            }
            return true;
        }
    };
    const vector<Point> dir { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    Point start, end;
    int count = 0;
public:
    int dfs (const vector<vector<int>> &map) {
        int m = static_cast<int>(map.size ());
        int n = static_cast<int>(map[0].size ());
        start = { 0, 0 };
        end = { m - 1, n - 1 };
        vector<vector<int>> mapVisited (m, vector<int> (n, 0));
        doDfs (map, mapVisited, { 0, 0 });
        return count;
    }
    void doDfs (const vector<vector<int>> &map, vector<vector<int>> mapVisited, const Point &pos) {
        if (!pos.inRange (start, end)) {
            return;
        }
        if (mapVisited[pos.x][pos.y] == 1 || map[pos.x][pos.y] == 1) {
            return;
        }
        if (pos == end) {
            count++;
            cout << "find path" << endl;
            return;
        }
        mapVisited[pos.x][pos.y] = 1;
        doDfs (map, mapVisited, { pos.x + 1, pos.y });
        doDfs (map, mapVisited, { pos.x - 1, pos.y });
        doDfs (map, mapVisited, { pos.x, pos.y + 1 });
        doDfs (map, mapVisited, { pos.x, pos.y - 1 });
        mapVisited[pos.x][pos.y] = 0;
    }
};
int main()
{
    // 1: wall
    // 0: road
    //start (0,0)
    // end (m- 1, n - 1)
    vector<vector<int>> map{
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 0},
    };
    Solution s;
    cout << s.dfs(map) << endl;
    return 0;
}