// 049-Group Anagrams.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> anaMap;
		for (unsigned int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if(anaMap.find(temp)!=anaMap.end()) anaMap[temp].push_back(strs[i]);
			else {
				vector<string> data;
				data.push_back(strs[i]);
				anaMap[temp] = data;
			}
		}
		vector<vector<string>> result;
		for (map<string,vector<string>>::iterator it = anaMap.begin(); it != anaMap.end(); ++it) {
			result.push_back(it->second);
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

