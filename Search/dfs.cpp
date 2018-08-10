#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class Solution {
    struct Point {
        int x = 0;
        int y = 0;
        Point() {}
        Point(int xValue, int yValue)
            : x(xValue)
            , y(yValue)
        {
        }
        bool operator==(const Point& other) const
        {
            return x == other.x && y == other.y;
        }
        Point& operator+(const Point& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }
        Point clone() const
        {
            return { this->x, this->y };
        }
        bool inRange(const Point& start, const Point& end) const
        {
            if (x < start.x || x > end.x) {
                return false;
            }
            if (y < start.y || y > end.y) {
                return false;
            }
            return true;
        }
    };
    const vector<Point> dir { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    Point start, end;
    int count = 0;

public:
    int dfs(const vector<vector<int>>& map)
    {
        int m = static_cast<int>(map.size());
        int n = static_cast<int>(map[0].size());
        start = { 0, 0 };
        end = { m - 1, n - 1 };
        vector<vector<int>> mapVisited(m, vector<int>(n, 0));
        string path;
        doDfs(map, mapVisited, { 0, 0 }, path);
        return count;
    }
    void doDfs(const vector<vector<int>>& map, vector<vector<int>> mapVisited, const Point& pos, string& path)
    {
        if (!pos.inRange(start, end)) {
            return;
        }
        if (mapVisited[pos.x][pos.y] == 1 || map[pos.x][pos.y] == 1) {
            return;
        }
        if (pos == end) {
            count++;
            cout << "find path " << path << endl;
            return;
        }
        path += "(" + to_string(pos.x) + "," + to_string(pos.y) + ") ";
        string tmpPath = path;
        mapVisited[pos.x][pos.y] = 1;
        doDfs(map, mapVisited, { pos.x + 1, pos.y }, path);
        doDfs(map, mapVisited, { pos.x - 1, pos.y }, path);
        doDfs(map, mapVisited, { pos.x, pos.y + 1 }, path);
        doDfs(map, mapVisited, { pos.x, pos.y - 1 }, path);
        mapVisited[pos.x][pos.y] = 0;
        path = tmpPath;
    }

    //int dfsCount(const vector<vector<int>>& map) const
    //{
    //    static const vector<pair<int, int>> dir {
    //        { -1, 0 },
    //        { 1, 0 },
    //        { 0, -1 },
    //        { 0, 1 },
    //    };
    //    int m = static_cast<int>(map.size());
    //    int n = static_cast<int>(map[0].size());
    //    vector<vector<int>> mapVisited(m, vector<int>(n, 0));
    //    stack<pair<int, int>> pointStack;
    //    int count = 0;
    //    int dx, dy;

    //    pointStack.push({ 0, 0 });
    //    mapVisited[0][0] = 1;

    //    while (!pointStack.empty()) {
    //        auto top = pointStack.top();
    //        pointStack.pop();
    //        if (top.first == m - 1 && top.second == n - 1) {
    //            count++;
    //            continue;
    //        }
    //        for (const auto& d : dir) {
    //            dx = top.first + d.first;
    //            dy = top.second + d.second;
    //            if (dx >= 0 && dx < m && dy >= 0 && dy < n && mapVisited[dx][dy] == 0 && map[dx][dy] == 0) {
    //                pointStack.push({ dx, dy });
    //                mapVisited[dx][dy] = 1;
    //                break;
    //            }
    //        }
    //    }
    //    return count;
    //}
};
int main()
{
    // 1: wall
    // 0: road
    //start (0,0)
    // end (m- 1, n - 1)
    vector<vector<int>> map {
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 0, 1, 0 },
        { 1, 0, 0, 0 },
    };
    Solution s;
    cout << s.dfs(map) << endl;
    //cout << s.dfsCount(map) << endl;
    return 0;
}
