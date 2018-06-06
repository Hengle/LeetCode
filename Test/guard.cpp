#include <iostream>
using namespace std;
class Guard {
public:
    Guard() {
        cout << "construct\n";
    }
    ~Guard() {
        cout << "destruct\n";
    }
};
int main() {
    {
        Guard a;
    }
    cout << "after\n";
    return 0;
}