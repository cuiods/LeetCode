// 017-Letter Combinations of a Phone Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string digitMapping[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> result;
		if (digits.empty()) return result;
		result.push_back("");
		for (unsigned int i = 0; i < digits.length(); i++) {
			string chars = digitMapping[digits[i]-'0'];
			vector<string> nextResult;
			for (unsigned int j = 0; j < result.size(); j++) {
				string tempStr = result[j];
				for (unsigned int k = 0; k  < chars.length(); k ++) {
					nextResult.push_back(tempStr+chars[k]);
				}
			}
			result = nextResult;
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

