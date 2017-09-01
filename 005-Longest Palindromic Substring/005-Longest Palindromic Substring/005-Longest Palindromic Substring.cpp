// 005-Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		const int sLen = s.length();
		if(sLen == 0) return s;
		bool** data = new bool*[sLen];
		string result = charToString(s[0]);
		int maxNum = 1;
		for (int i = 0; i < sLen; i++) {
			data[i] = new bool[sLen];
		}
		for (int i = 0; i < sLen; i++) {
			for (int j = 0; j + i < sLen; j++) {
				if (i == 0)
					data[j][j+i] = true;
				else if (i == 1)
					data[j][j+i] = s[j]==s[j+i]? true: false;
				else 
					data[j][j+i] = s[j]==s[j+i]? data[j+1][j+i-1]: false;
				if (data[j][j+i] && i+1 > maxNum) {
					maxNum = i+1;
					result = s.substr(j,maxNum);
				}
			}
		} 
		return result;
    }

	string charToString(char c) {
		string str;
		stringstream streamStr;
		streamStr << c;
		return streamStr.str();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << Solution().longestPalindrome("cbbd") << endl;
	system("pause");
	return 0;
}

