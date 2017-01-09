#include <iostream>
using namespace std;
#include <string>
#include <stack>
class Solution {
public:
	bool isValid(string s) {
		return false;
//		stack<char> stk;
//		for (int i = 0; i < s.length() ; i++) {
//			switch (s[i]) : {
//				case '[':{
//					break;
//				}
//				case '{': {
//					break;
//				}
//				case '(':{
//					break;
//				}
//				case ')':{
//					break;
//				}
//				case ']':{
//					break;
//				}
//				case '}':{
//					break;
//				}
//				default:
//					break;

//			}
//		}
	}
};
using namespace std;

int main()
{
	Solution sol;
	cout << sol.isValid("{[()()]}") << endl;
	return 0;
}

