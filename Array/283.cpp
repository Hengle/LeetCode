#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void moveZeroes(vector<int>& nums)
{
	int tmp;
	for (int i =0, j = 0; i < nums.size(); i++) {
		if(nums[i]!=0) {
			tmp = nums[i];
			nums[i] =nums[j];
			nums[j] = tmp;

			j++;
		}
	}

}
//void moveZeroes(vector<int>& nums)
//{
//	vector<int> copy;
//	for (int i = 0; i < nums.size(); i++) {
//		if (nums[i]!=0)
//			copy.push_back(nums[i]);
//	}
//	for (int i = 0; i < copy.size(); i++)
//		nums[i]= copy[i];
//	for (int i = copy.size(); i < nums.size(); i++)
//		nums[i] = 0;

//}
//void moveZeroes(vector<int>& nums)
//{
//	int i = 0;
//	while(i < nums.size()) {
//		if (nums[i] == 0) {
//			int j = i + 1;
//			while(j < nums.size() && nums[j]==0)
//				j++;
//			if (j < nums.size()) {
//				nums[i] = nums[j];
//				nums[j] = 0;
//			}
//		}
//		i++;
//	}

//}

//void moveZeroes(vector<int>& nums)
//{
//	int sum = 0;
//	for (int i = 0; i<nums.size(); i++)
//	{
//		if(nums.at(i) != 0)
//			sum++;
//	}
//	if (sum >= nums.size())
//		return ;

//	for (int i = 0; i < sum; i++)
//	{
//		if (nums[i]!=0)
//			continue;
//		int j = i + 1;
//		while(j < nums.size() && nums[j] == 0)
//			j++;
//		if (j < nums.size()) {
//			nums[i] = nums[j];
//			nums[j] = 0;
//		}
//	}
//}
int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(0);
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout<<nums[i]<<endl;
	}

	return 0;
}

