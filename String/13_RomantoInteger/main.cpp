#include <iostream>

int map(char c)
{
	switch (c)
	{
		case 'I': return 1;
		case 'X': return 10;
		case 'C': return 100;
		case 'M': return 1000;
		case 'V': return 5;
		case 'L': return 50;
		case 'D': return 500;
		default: return 0;
	}
}
using namespace std;
int romanToInt(string s) {
	if (s.length() < 1)
		return 0;
	int ret = 0;
	int sub = map(s[0]);
	int lastv = sub;
	for (int i = 1; i <s.length() ; ++i) {
		int cov = map(s[i]);
		if (cov == lastv) {
			sub += cov;
		} else if (cov > lastv) {
			sub = cov -sub;
		} else {
			ret += sub;
			sub = cov;
		}
		lastv = cov;
	}
	ret += sub;
	return ret;
}
int main(int argc, char *argv[])
{
	cout << "Hello World!" << endl;
	return 0;
}
