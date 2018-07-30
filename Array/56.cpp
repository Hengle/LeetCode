#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval()
        : start(0)
        , end(0)
    {
    }
    Interval(int s, int e)
        : start(s)
        , end(e)
    {
    }
};
bool cmpInterval(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        sort(intervals.begin(), intervals.end(), cmpInterval);
        vector<Interval> ans;
        map<int, int> iMap;
        for (auto i : intervals) {
            //找到第一个小于i.start的 key,
            //if i.start <= key.value;
            //    [key] = max(i.end, key.value)
            //else
            //    [i.start] = i.value;
            if (iMap.empty()) {
                iMap[i.start] = i.end;
                continue;
            }
            auto last = iMap.cbegin();
            for (auto it = iMap.cbegin(); it != iMap.cend(); ++it) {
                if (it->first <= i.start) {
                    if (it->first > last->first) {
                        last = it;
                    }
                }
            }
        }

        for (auto it = iMap.cbegin(); it != iMap.cend(); it++) {
            ans.push_back({ it->first, it->second });
        }
        return ans;
    }
};
int main()
{
    vector<Interval> v{
        { 1, 3 },
        { 2, 6 },
        { 8, 10 },
        { 15, 18 }
    };
    Solution s;
    auto ans = s.merge(v);
    for (auto val : ans) {
        cout << val.start << " " << val.end << endl;
    }
    return 0;
}