#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
	return a < b;
}
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), comp);
	bool ret = false;
	int i = 1;
	while (i < nums.size() && ret == false) {
		if (nums[i] == nums[i-1]) {
			ret = true;
			break;
		}
		i++;
	}
	return ret;
}
int main()
{
	cout << "Hello World!" << endl;
	return 0;
}

