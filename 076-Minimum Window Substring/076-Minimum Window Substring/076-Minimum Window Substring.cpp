// 076-Minimum Window Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
		vector<int> map(128,0);
		int counter = t.size();
		int begin = 0, end = 0;
		int d = INT_MAX, head = 0;
		for(auto c: t) map[c]++;
		while (end<s.size()) {
			if (map[s[end++]]-->0) counter--;
			while(counter==0) {
				if (end-begin<d) d = end - (head = begin);
				if (map[s[begin++]]++==0) counter++;
			}
		}
		return d == INT_MAX? "": s.substr(head,d);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

