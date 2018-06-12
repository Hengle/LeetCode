#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
class MyCalendar {
public:
  MyCalendar() {}

  bool book(int start, int end) {
      if (mMap.size() <= 0) {
          mMap[start] = end - 1;
          return true;
      }
      
      auto it = mMap.cbegin();
      it++;
      while (it->second < start) {
          it++;
      }
      if (it->first > end) {
          mMap[start] = end - 1;
          return true;
      } else {
          return false;
      }
  }

private:
  map<int, int> mMap;
};
int main() {}
