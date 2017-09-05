// 022-Generate Parentheses.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		generate("",n,n,result);
		return result;
    }

	void generate(string current, int left, int right, vector<string>& result) {
		if(left==0 && right==0) result.push_back(current);
		if(left)
			generate(current+"(", left-1, right, result);
		if(right && right>left) 
			generate(current+")", left, right-1, result);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

