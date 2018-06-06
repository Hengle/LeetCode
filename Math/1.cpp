#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef struct _data{
	int value;
	int index;
}data;
//bool comp(data a, data b)
//{
//	return a.value < b.value;
//}

//vector<int> twoSum(vector<int>& nums, int target)
//{
//	vector<int> ret;
//	vector<data> datas;
//	for (int i = 0; i < nums.size(); i++) {
//		data tmp;
//		tmp.value = nums[i];
//		tmp.index = i;
//		datas.push_back(tmp);
//	}
//	sort(datas.begin(), datas.end(), comp);
//	int l = 0, r = nums.size() - 1;
//	while (l < r) {
//		if (datas[l].value + datas[r].value == target) break;
//		if (datas[l].value + datas[r].value > target)
//			r--;
//		else
//			l++;
//	}
//	ret.push_back(datas[l].index);
//	ret.push_back(datas[r].index);
//	return ret;
//}

int main()
{
//	vector<int> nums;
//	nums.push_back(2);
//	nums.push_back(7);
//	nums.push_back(11);
//	nums.push_back(15);
//	vector <int> s = twoSum(nums, 9);
//	for (int i =0 ; i < s.size(); i++) {
//		cout <<s[i];
//	}
//	return 0;
}

