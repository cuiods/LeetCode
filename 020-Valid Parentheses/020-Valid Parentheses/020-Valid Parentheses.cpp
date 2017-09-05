// 020-Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> signStack;
		for(unsigned int i = 0; i < s.length(); i++) {
			char tempChar = s[i];
			if (tempChar=='(' || tempChar=='{' || tempChar=='[') signStack.push(tempChar);
			else {
				if (signStack.empty()) return false;
				char topChar = signStack.top();
				if ((tempChar==')'&&topChar=='(') || (tempChar=='}'&&topChar=='{') || (tempChar==']'&&topChar=='['))
					signStack.pop();
				else return false;
			}
		}
		bool result = signStack.empty();
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().isValid(")");
	return 0;
}

