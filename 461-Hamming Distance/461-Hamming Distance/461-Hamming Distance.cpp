// 461-Hamming Distance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		if (x == y) return 0;
        int z = x^y;
		int num = 0;
		while(z) {
			num += 1 & z;
			z = z >> 1;
		}
		return num;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution().hammingDistance(1,4);
	return 0;
}

