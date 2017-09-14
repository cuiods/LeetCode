// 282-Expression Add Operators.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
		helper(result, num, target, "", 0, 0, 0);
		return result;
    }

	void helper(vector<string>& result, string& num, int target, string path, int start, long current,long multi) {
		if (start == num.length() && current == target) result.push_back(path);
		for (unsigned int i = start; i < num.length(); i++) {
			if (i != start && num[start] == '0') break;
			string currentStr = num.substr(start, i-start+1);
			long temp = atol(currentStr.c_str());
			if (start == 0) helper(result,num,target,currentStr,i+1, temp, temp);
			else {
				helper(result,num,target,path+"+"+currentStr,i+1, current+temp, temp);
				helper(result,num,target,path+"-"+currentStr,i+1, current-temp, -temp);
				helper(result,num,target,path+"*"+currentStr,i+1, current-multi+multi*temp, multi*temp);
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

