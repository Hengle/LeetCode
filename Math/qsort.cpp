#include <iostream>

using namespace std;

void Jqsort(int a[], int left, int right)
{
    int mid = left + (right - left)/2;
    int i = left;
    int j = right;
    int t;
    while (i <=j){
        while (a[i] < a[mid]) i++;
        while (a[j] > a[mid]) j--;
        if (i <= j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i < right) Jqsort(a, i, right);
    if (left < j) Jqsort(a, left, j);
}
int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int a [10] = {1, 43 ,12, 12, 12 ,123, 123, 1234, 314, 4};
    Jqsort(a, 0, 9);
    int count = 0;
    for (const auto &i : a) {
        cout << count++ << ": "  << i << endl;
    }
    return 0;
}
