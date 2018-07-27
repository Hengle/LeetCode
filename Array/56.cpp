#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool compInterval(const Interval &a, const Interval &b) {
	return a.start < b.start;
}
bool canMerge(const Interval &a, const Interval &b) {
	if (a.start <= b.start && b.start <= a.end) {
		return true;
	}
	return false;
}
class Solution {
public:

	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ans;
		if (intervals.size() < 1) {
			return ans;
		}
		sort(intervals.begin(), intervals.end(), compInterval);
		ans.push_back(intervals.front());

		for (int i = 1; i < intervals.size(); ++i) {
			int pos = -1;
			for (int index = 0; index < ans.size(); ++index) {
				if (canMerge(ans[index], intervals[i])) {
					pos = index;
				}
			}
			if (pos != -1) {
				ans[pos].end = max(ans[pos].end, intervals[i].end);
			} else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
};
int main() {
	//vector<Interval> v {
	//    {1,3},
	//    {2,6},
	//    {8,10},
	//    {15,18}
	//};
	vector<Interval> v{
		{1,4},
		{4, 5},
	};
	Solution s;
	auto ans = s.merge(v);
	for (auto i : ans) {
		cout << i.start << " " << i.end << endl;
	}
	return 0;
}