// 301-Remove Invalid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
		removeParentheses(s,result,0,0,true);
		return result;
    }

	void removeParentheses(string s, vector<string>& result, int start, int lastRemove, bool order) {
		char left, right;
		if (order) {left = '('; right = ')';}
		else {left = ')'; right = '(';}
		int counter = 0;
		for (int i = start; i < s.length(); i++) {
			if (s[i] == left) counter++;
			else if(s[i] == right) counter--;
			if (counter >= 0) continue;
			for (int j = lastRemove; j <= i; j++) {
				if (s[j]==right && (j == lastRemove || s[j-1]!=right))
					removeParentheses(s.substr(0,j)+s.substr(j+1, s.length()-j-1),result,i,j, order);
			}
			return;
		}
		if (order) {
			reverse(s.begin(),s.end());
			removeParentheses(s, result, 0, 0, false);
		} else {
			reverse(s.begin(),s.end());
			result.push_back(s);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().removeInvalidParentheses("()())()");
	return 0;
}

