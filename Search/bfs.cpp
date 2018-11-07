#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::queue;
using std::cout;
using std::endl;
using std::min;
class Solution {
    struct Point {
        int x = 0;
        int y = 0;
        Point (int xValue, int yValue) : x (xValue), y (yValue) {}
        bool operator== (const Point &other) const{
            return x == other.x && y == other.y;
        }
        Point & operator+ (const Point &other) {
            x += other.x;
            y += other.y;
            return *this;
        }
        Point clone () const {
            return { this->x, this->y };
        }
        bool inRange (const Point & start, const Point &end) {
            if (x < start.x || x > end.x) {
                return false;
            }
            if (y < start.y || y > end.y) {
                return false;
            }
            return true;
        }
    };
public:
    const vector<Point> dir{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int bfs (const vector<vector<int>> &map) {
        int m = static_cast<int>(map.size ());
        int n = static_cast<int>(map[0].size ());
        const Point start{ 0, 0 };
        const Point end{ m - 1, n - 1 };
        queue<Point> pointQueue;
        vector<vector<int>> mapStep (m, vector<int> (n, 0));

        pointQueue.push (start);
        while (!pointQueue.empty ()) {
            const Point &front = pointQueue.front ();
            pointQueue.pop ();
            if (front == end) {
                break;
            }
            for (const auto &i : dir) {
                auto pos = front.clone () + i;
                if (pos.inRange (start, end) && map[pos.x][pos.y] == 0) {
                    pointQueue.push (pos);
                    mapStep[pos.x][pos.y] = mapStep[front.x][front.y] + 1;
                }
            }
        }
        return mapStep[end.x][end.y];
    }
};
int main () {
    // 1: wall
    // 0: road
    //start (0,0)
    // end (m- 1, n - 1)
    vector<vector<int>> map{
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 0},
    };
    Solution s;
    cout << s.bfs (map) << endl;
    return 0;
}