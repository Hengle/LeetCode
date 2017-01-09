#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		datas.push_back(x);
		if(mins.empty())
			mins.push_back(x);
		else
			mins.push_back(min(mins.back(), x));
	}

	void pop() {
		datas.pop_back();
		mins.pop_back();
	}

	int top() {
		return datas.back();
	}

	int getMin() {
		return mins.back();
	}
	vector<int> datas;
	vector<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main()
{
//	MinStack obj;
//	obj.push(12);
//	obj.pop();
//	int param_3 = obj.top();
//	int param_4 = obj.getMin();
//	cout<<param_3<<" "<<param_4;
//	return 0;
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.getMin();
	minStack.pop();
	cout<<minStack.top();
	cout<<minStack.getMin();
	return 0;
}

