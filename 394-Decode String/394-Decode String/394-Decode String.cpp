// 394-Decode String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
		return decodeString(s,i);
    }

	string decodeString(string& s, int& i) {
		string result;
		for (; i < s.length() && s[i]!=']'; i++) {
			if (!isdigit(s[i])) {
				result.push_back(s[i]);
				continue;
			}
			string digit; digit.push_back(s[i]);
			while (s[++i]!='[') digit.push_back(s[i]);
			int loop = atoi(digit.c_str());
			string temp = decodeString(s,++i);
			for (int j = 0; j < loop; j++) result+=temp;
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().decodeString("3[a]2[bc]");
	return 0;
}

