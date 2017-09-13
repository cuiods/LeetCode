// 279-Perfect Squares.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		if (n <= 0) return 0;
        vector<int> dp(n+1,INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				dp[i] = min(dp[i], dp[i-j*j]+1);
			}
		}
		return dp[n];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

