// 032-Longest Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> test;
		int maxLength = 0;
		test.push(-1);
		for (int i = 0; i < s.length(); i++) {
			if(s[i]=='(') test.push(i);
			else {
				test.pop();
				if (test.empty()) test.push(i);
				else maxLength = max(maxLength, i-test.top());
			}
		}
		return maxLength;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

