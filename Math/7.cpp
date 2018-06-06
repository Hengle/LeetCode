#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
int reverse(int x) {
	long ret = 0;
	while(x!=0) {
		ret = ret * 10 + x %10;
		x = x /10;
	}
	if (ret > 0)
		return ret > INT_MAX ? 0 : ret;
	else
		return ret < INT_MIN ? 0: ret;

}
int main(int argc, char *argv[])
{
	cout << reverse(1534236469) << endl;
	return 0;
}
