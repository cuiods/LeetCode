// 560-Subarray Sum Equals K.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0) return 0;
        vector<int> dp(nums.size()+1,0);
		int count = 0;
		for (unsigned int i = 0; i < nums.size(); i++) {
			dp[i] = 0;
			for (int j = i; j < nums.size(); j++) {
				dp[j+1] = dp[j]+nums[j];
				if (dp[j+1]==k) count++;
			}
		}
		return count;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

