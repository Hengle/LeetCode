#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
	if(nums.size() == 0)
		return 0;
	int i = 0;
	int j = 0;
	for (int i = 1; i < nums.size(); i++) {
		if(nums[j] != nums[i]) {
			nums[++j] = nums[i];
		}
	}
	return j+1;
}

int removeDuplicates_27(vector<int>& nums) {
	if(nums.size() == 0)
		return 0;
	int i = 0;
	int j = 0;
	int rp = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[j] == nums[i]) {
			rp++;
			if (rp < 2)
				nums[++j] = nums[i];
		} else {
			rp = 0;
			nums[++j] = nums[i];
		}
	}
	return j+1;
}

int main(int argc, char *argv[])
{
	cout << "Hello World!" << endl;
	return 0;
}
