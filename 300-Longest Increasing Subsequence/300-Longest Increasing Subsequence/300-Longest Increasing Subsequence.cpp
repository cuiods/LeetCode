// 300-Longest Increasing Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
		int maxNum = 1;
		for (unsigned int i = 1; i < nums.size(); i++) {
			int j = i-1;
			int maxIndex = -1;
			int currentMax = 1;
			for (; j-currentMax+1 >= 0; j--) {
				if (nums[j]<nums[i] && dp[j] >= currentMax) {
						currentMax = dp[j];
						maxIndex = j;
				}
			}
			if (maxIndex >= 0) {
				dp[i] = dp[maxIndex]+1;
				maxNum = max(maxNum, dp[i]);
			}
		}
		return maxNum;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int ints[9] = {1,3,6,7,9,4,10,5,6};
	vector<int> p(ints, ints+sizeof(ints)/sizeof(int));
	Solution().lengthOfLIS(p);
	return 0;
}

