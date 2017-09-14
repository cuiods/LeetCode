// 416-Partition Equal Subset Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		if (nums.size() == 0) return true;
		int sum = 0;
		for (auto c: nums) sum+=c;
		if (sum%2 == 1) return false;
		vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1,false));
		dp[0][0] = true;
		for (int i = 1; i < dp.size(); i++) {
			dp[i][0] = true;
			for (int j = 1; j < dp[i].size(); j++) {
				dp[i][j] = dp[i-1][j];
				if (j-nums[i-1]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
			}
		}
		return dp[nums.size()][sum/2];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int myints[3] = {1,2,5};
	vector<int> param(myints, myints+sizeof(myints)/sizeof(int));
	Solution().canPartition(param);
	return 0;
}

