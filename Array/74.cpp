#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int binarySearch(const vector<int>& orderedArray, int target)
{
    int start = 0;
    int end = orderedArray.size();
    int index = -1;
    int ret = -1;
    while (start < end) {
        index = start + (end - start) / 2;
        if (orderedArray[index] > target) {
            end = index;
        } else if (orderedArray[index] < target) {
            start = index + 1;
        } else {
            ret = index;
            break;
        }
    }
    return ret;
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size();
        if (rows <= 0) {
            return false;
        }
        int cols = matrix.at(0).size();
        if (cols <= 0) {
            return false;
        }

        int start = 0;
        int end = rows * cols;
        int index;
        while (start < end) {
            index = start + (end - start) / 2;
            if (matrix[index / cols][index % cols] > target) {
                end = index;
            } else if (matrix[index / cols][index % cols] < target) {
                start = index + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
    Solution s;

    cout << s.searchMatrix(matrix, 4) << endl;

    return 0;
}