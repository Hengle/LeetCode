#include <iostream>
#include <numeric>
#include <time.h>
using namespace std;

string convert(string s, int numRows)
{
	if (numRows <=0)
		return "";
	if (numRows == 1 || s.length() < numRows)
		return s;
	int n = s.length();
	string str[numRows];

	for (int i = 0; i < n;) {
		for (int j = 0; j < numRows && i < n; ++j, ++i) {
			str[j].push_back(s[i]);
		}
		for (int j = numRows -2; j >0 && i <n; --j, ++i) {
			str[j].push_back(s[i]);
		}
	}
	string ret;
	for (int i =0; i < numRows; i++)
		ret.append(str[i]);
	return ret;
}
int main(int argc, char *argv[])
{
	double start = clock();
	string ret = convert("ABC", 2);
	double end = clock();
	cout <<ret << end -start<<endl;
	return 0;
}
