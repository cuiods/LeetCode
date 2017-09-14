// 494-Target Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int m = nums.size();
		int n = 1;
		for (auto c: nums) n+=abs(c);
		if ((n-1+S)%2 == 1) return 0;
		if (m == 0) return S == 0? 1: 0;
		if (S>n) return 0;
		vector<vector<int>> dp(m+1, vector<int>(2*n+1,0));
		dp[0][n] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j <= 2*n; j++) {
				if (j-nums[i-1]>=0 && j - nums[i-1]<=2*n) dp[i][j] += dp[i-1][j-nums[i-1]];
				if (j+nums[i-1]>=0 && j + nums[i-1]<=2*n) dp[i][j] += dp[i-1][j+nums[i-1]];
			}
		}
		return dp[m][S+n];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int muints[5] = {1,1,1,1,1};
	vector<int> param(muints, muints+sizeof(muints)/sizeof(int));
	Solution().findTargetSumWays(param,3);
	return 0;
}

