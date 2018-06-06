#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        for (auto num :  findNums) {
            int ans = -1;
            int i = 0;
            //find num pos;
            while (i < nums.size() && num != nums[i])
                i++;
            //find greater num
            while (i < nums.size() && num >= nums[i])
                i++;
            if (i < nums.size()) {
                ans = nums[i];
            }

            ret.push_back(ans);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    vector<int> fn, nums;
//    {
//        //case 1
//        nums.push_back(1);
//        nums.push_back(3);
//        nums.push_back(4);
//        nums.push_back(2);

//        fn.push_back(4);
//        fn.push_back(1);
//        fn.push_back(2);
//    }

    {
        //case 2
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(4);

        fn.push_back(2);
        fn.push_back(4);
    }

    Solution s;
    vector<int> ret = s.nextGreaterElement(fn, nums);
    for (auto i : ret) {
        cout << i << endl;
    }
    return 0;
}
