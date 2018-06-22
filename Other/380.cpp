#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class RandomizedSet
{
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
    bool insert(int val)
    {
        if (valueMap.find(val) == valueMap.end())
        {
            values.push_back(val);
            valueMap[val] = values.size() - 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
    bool remove(int val)
    {
        if (valueMap.find(val) == valueMap.end())
        {
            return false;
        }
        else
        {
            int last = values.back();
            int index = valueMap[val];
            values[index] = last;
            values.pop_back();
            valueMap[last] = index;
            valueMap.erase(val);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() { return values[rand() % values.size()]; }

  private:
    vector<int> values;
    unordered_map<int, int> valueMap;
};
int main()
{
    RandomizedSet s;
    cout << s.insert(1) << endl;
    cout << s.remove(2) << endl;
    cout << s.insert(2) << endl;
    cout << s.getRandom() << endl;
    cout << s.remove(1) << endl;
    cout << s.insert(2) << endl;
    cout << s.getRandom() << endl;

    // RandomizedSet s;
    // cout << s.insert(0) << endl;
    // cout << s.insert(1) << endl;
    // cout << s.remove(0) << endl;
    // cout << s.insert(2) << endl;
    // cout << s.remove(1) << endl;
    // cout << s.getRandom() << endl;
}