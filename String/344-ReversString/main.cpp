#include <iostream>
#include <string>
using namespace std;
string reverseString(string s) {
	string ret = s;
	int len = ret.size();
	int mid = len / 2;
	for (int i = 0; i < mid; i++)
	{
		char c = ret[i];
		ret[i] = ret[len - 1 - i];
		ret[len - 1 - i] = c;
	}
	return ret;
}
int main()
{
	string str("Hello World!");
	cout << reverseString(str) << endl;
	return 0;
}

