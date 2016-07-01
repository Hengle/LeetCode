#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>& digits)
{
	int n = digits.size() -1;
	if (n <0) {
		return digits;
	}

	digits[n] = digits[n] + 1;
	for (int i = n -1; i >=0; i--) {
		digits[i] += digits[i + 1] /10;
		digits[i + 1] %= 10;
	}
	int append = digits[0] / 10;
	digits[0] = digits[0] % 10;
	if (append > 0) {

		digits.insert(digits.begin(), append);
	}
	return digits;
}
int main(int argc, char *argv[])
{
	vector<int> v;
	v.push_back(9);
	v.push_back(9);
	v = plusOne(v);
	for (int i = 0; i < v.size() ; ++i) {
		cout<< v[i];
	}

	return 0;
}
