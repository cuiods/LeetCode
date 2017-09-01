// 003-Longest Substring Without Repeating Characters.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
		map<char,int> characters; 
		int start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (s.length() - start < maxLen) break;
			if (characters.find(s[i]) != characters.end() && characters[s[i]] > start) {
				start = characters[s[i]];
			}
			characters[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int result = Solution().lengthOfLongestSubstring("pwwkew");
	cout << result << endl;
	system("pause");
	return 0;
}

