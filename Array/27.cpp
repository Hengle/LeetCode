#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val)
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == val)
			continue;
		nums[j] = nums[i];
		j++;
	}
	return j;
}
int main(int argc, char *argv[])
{
	cout << "Hello World!" << endl;
	return 0;
}
