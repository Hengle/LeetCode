#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLongestSubstring(string s)
{
	int t[256], len, start = 0, end = 0, maxLength =0;
//	memset(t, 0xff, 256*sizeof(int));
	len = s.length();
	while(end != len) {
		if(t[s[end]]> start) {
			if (maxLength < end-start) {
				maxLength = end -start;
			}
			start = t[s[end]] +1;
		}
		t[s[end]] = end;
		++end;
	}
}
int main(int argc, char *argv[])
{
	cout << lengthOfLongestSubstring("abcbad") << endl;
	return 0;
}
