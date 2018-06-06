#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
  public:
    // int thirdMax(vector<int> &nums)
    // {
    //     set<int> s;
    //     for (auto i : nums)
    //     {
    //         s.insert(i);
    //         if (s.size() > 3) {
    //             s.erase(s.begin());
    //         }
    //     }
    //     return s.size() == 3 ? *s.begin() : *s.rbegin();
    // }
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, thrid = LONG_MIN;
        for (auto i : nums) {
            if (i > first) {
                thrid = second;
                second = first;
                first = i;
            } else if (i > second && i < first) {
                thrid = second;
                second = i;
            } else if (i > thrid && i < second)  {
                thrid = i;
            }
        }
        return (thrid == LONG_MIN || thrid == second) ? first : thrid; 
    }
};
int main()
{

    Solution s;

    {
        vector<int> v{3, 2, 1};
        cout << s.thirdMax(v) << endl;
    }
    {
        vector<int> v{1, 2};
        cout << s.thirdMax(v) << endl;
    }
    {
        vector<int> v{2, 2, 3, 1};
        cout << s.thirdMax(v) << endl;
    }
    {
        vector<int> v{2, 2, 5};
        cout << s.thirdMax(v) << endl;
    }
    return 0;
}