// 139-Word Break.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		vector<int> hasIndex;
		hasIndex.push_back(-1);
		map<string,bool> words;
		bool result = false;
		for (unsigned int i = 0; i < wordDict.size(); i++) 
			words.insert(pair<string,bool>(wordDict[i],true));
		for (unsigned int i = 0; i < s.length(); i++) {
			for (int j = hasIndex.size()-1; j >= 0; j--) {
				int start = hasIndex[j]+1;
				int end = i-hasIndex[j];
				if (words.find(s.substr(hasIndex[j]+1,i-hasIndex[j]))!=words.end()) {
					hasIndex.push_back(i);
					if (i == s.length()-1) result = true;
					break;
				}
			}
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "leetcode";
	vector<string> param;
	param.push_back("leet");
	param.push_back("code");
	Solution().wordBreak(s,param);
	return 0;
}

