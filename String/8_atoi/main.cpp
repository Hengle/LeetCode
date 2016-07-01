#include <iostream>
#include <string>
using namespace std;
int myAtoi(string str)
{
	if (str.length() <=0)
		return 0;
	int start = 0;
	int sig = 1;
	int sigpos = -1;
	int hassig = 0;
	int err = 0;
	while(start < str.length() && str[start] < '0' ||str[start] >'9' ) {
		if (str[start] =='-') {
			if (!hassig) {
				sig = -1;
				hassig = 1;
				sigpos = start;
			} else err = 1;
		} else if (str[start]== '+'){
			if (!hassig){
				sig = 1;
				hassig = 1;
				sigpos = start;
			} else err = 1;
		} else if (str[start]!=' ')
			err = 1;
		++start;
	}
	if (err == 1 || hassig==1 && sigpos != start -1)
		return 0;
	long long ret = 0;
	for (int i = start; i < str.length() ; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			ret = ret * 10 + (str[i] -'0');
			if (sig == -1 && ret * -1 < INT_MIN)
			{
				return INT_MIN;
			} else if (sig == 1 && ret  > INT_MAX) {
				return INT_MAX;
			}
		}
		else
			break;
	}
	if (sig == -1)
		return (ret * -1) < INT_MIN ? INT_MIN : (ret * -1);
	else
		return ret > INT_MAX ? INT_MAX : ret;

}
int main(int argc, char *argv[])
{
	cout << myAtoi("2147483648") << endl;
	return 0;
}
