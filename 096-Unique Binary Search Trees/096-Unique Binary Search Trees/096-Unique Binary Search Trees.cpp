// 096-Unique Binary Search Trees.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> data(n+1,0);
		data[0] = 1;
		data[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				data[i] += data[j]*data[i-1-j];
			}
		}
		return data[n];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().numTrees(2);
	return 0;
}

