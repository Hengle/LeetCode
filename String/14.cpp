#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() ==0)
			return "";
		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++) {

			if (prefix.length() == 0 || strs[i].length() == 0)
				return "";
			int len = prefix.length() < strs[i].length() ?  prefix.length() : strs[i].length();
			int j;
			for (j = 0; j < len; j++) {
				if (prefix[j] != strs[i][j])
					break;
			}
			prefix = prefix.substr(0, j);
		}
		return prefix;
	}
};
int main()
{
	Solution slo;
	vector<string> strs;
	strs.push_back(string("abc0"));
	strs.push_back(string("abc1"));
	strs.push_back(string("abc2"));
	strs.push_back(string("abc"));


	cout << slo.longestCommonPrefix(strs);
	return 0;
}

