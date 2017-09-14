// 438-Find All Anagrams in a String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.length() == 0 ) return res;
		if (p.length() == 0) {
			for (int i = 0; i < s.length(); i++) res.push_back(i);
			return res;
		}
        vector<int> alphabet(26,0);
		for (auto c: p) alphabet[c-'a']++;
		int slength = s.length();
		int start = 0, end = 0, counter = p.length();
		while (end < slength) {
			if (alphabet[s[end++]-'a']-- > 0) {
				counter--;
				if (counter == 0) {
					res.push_back(start);
					alphabet[s[start++]-'a']++;
					counter++;
				}
			} else while (start<end ) {
				int temp = alphabet[s[start++]-'a']++;
				if (temp < 0) break;
				else if (temp >= 0) counter++;
			}
		}
		return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().findAnagrams("aaabaaa","aa");
	return 0;
}

