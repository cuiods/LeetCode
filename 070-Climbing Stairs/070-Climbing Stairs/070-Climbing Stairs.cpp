// 070-Climbing Stairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int climbStairs(int n) {
        int *ways = new int[n];
		ways[0] = 1; ways[1] = 2;
		for (int i = 2; i < n; i++) ways[i] = ways[i-1]+ways[i-2];
		return ways[n-1];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

