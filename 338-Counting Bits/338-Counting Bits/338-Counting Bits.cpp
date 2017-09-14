// 338-Counting Bits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
		for (int i = 1; i <= num; i++) res[i] = res[i&(i-1)]+1;
		return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

