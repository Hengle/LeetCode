#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	vector<int> dp;

	int start = 0;
	for (int i = 1; i < s.length(); i++) {
		int j = start;
		bool repeat = false;
		while ( j < i) {
			if (s[j] == s[i]) {
				repeat = true;
				break;
			}
			j++;
		}
		dp.push_back(j - start + 1);
		if (repeat) {
			start = i;
		}
	}

	int ret = -1;
	for (int i = 1; i <dp.size(); i++) {
		if (dp[i] > ret) {
			ret = dp[i];
		}
	}
	return ret;
}
int main(int argc, char *argv[])
{
	cout << lengthOfLongestSubstring("abcbdefa") << endl;
	return 0;
}
