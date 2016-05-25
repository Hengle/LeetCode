#include <iostream>

using namespace std;
int addDigits(int num)
{
	return 1 + (num - 1)%9;
}
int main()
{
	cout <<addDigits(1234)<<endl;
	return 0;
}

