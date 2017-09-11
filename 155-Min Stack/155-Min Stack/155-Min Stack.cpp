// 155-Min Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:
	stack<int> data;
	stack<int> minValue;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
		data.push(x);
		minValue.push(minValue.empty()?x:min(minValue.top(), x));
    }
    
    void pop() {
		data.pop();
		minValue.pop();
    }
    
    int top() {
		return data.top();
    }
    
    int getMin() {
		return minValue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

