#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int b)
{
	return a < b;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> ret;
	vector<int> n1, n2;
	n1 = nums1;
	n2 = nums2;
	sort(n1.begin(), n1.end(), comp);
	sort(n2.begin(), n2.end(), comp);

	int i = 0, j = 0;
	while (i< n1.size() && j < n2.size()) {
		if (n1[i] < n2[j]) {
			i++;
		} else if (n1[i] > n2[j]) {
			j++;
		} else {
			ret.push_back(n1[i]);
			i++;
			j++;
		}
	}
	vector<int>::iterator end;
	end = unique(ret.begin(), ret.end());
	ret.erase(end, ret.end());
	return ret;
}
int main()
{
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);

	nums2.push_back(2);
	nums2.push_back(2);

	vector<int> ret;
	ret = intersection(nums1, nums2);
	for(int i = 0; i < ret.size(); i++)
		cout<<ret[i]<<endl;
	return 0;
}

