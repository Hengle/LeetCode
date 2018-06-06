#include <iostream>

using namespace std;
bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	if (x < 10)
		return true;

	long left = 1;
	long right = 1;

	long d = 0;
	int t = x;
	while (t) {
		t = t / 10;
		d++;
	}
	for (int i = 1; i < d; ++i)
		left *= 10;

	while (left >= right) {
		if (x / left % 10 != x / right % 10) {
			return false;
		}
		right *= 10;
		left  /= 10;
	}
	return true;
}
int main(int argc, char *argv[])
{
	cout << isPalindrome(1000000001) << endl;
	return 0;
}
