// Forward declaration of isBadVersion API.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int badVersion = 4;
int callCount = 0;
bool isBadVersion(int version) {
    callCount++;
    cout << "call count" << callCount << " with version " << version << endl;
    return badVersion == version;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage:" << argv[0] << " Number BadVersion" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    badVersion = atoi(argv[2]);
    Solution s;
    auto v = s.firstBadVersion(n);
    cout << "bad " << v << endl;
    return 0;
}