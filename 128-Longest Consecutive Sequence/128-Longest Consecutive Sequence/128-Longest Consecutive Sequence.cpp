// 128-Longest Consecutive Sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> occurTimes;
		int maxNum = 0;
		for (unsigned int i = 0; i < nums.size(); i++) {
			int left = 0, right = 0;
			if (occurTimes.find(nums[i])!=occurTimes.end()) continue;
			left = occurTimes.find(nums[i]-1)==occurTimes.end() ? 0: occurTimes[nums[i]-1];
			right = occurTimes.find(nums[i]+1)==occurTimes.end() ? 0: occurTimes[nums[i]+1];
			int sum = left + right + 1;
			maxNum = max(maxNum, sum);
			occurTimes[nums[i]] = sum;
			occurTimes[nums[i]-left] = sum;
			occurTimes[nums[i]+right] = sum;
		}
		return maxNum;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int data[4] = {1,2,0,1};
	vector<int> param(data, data+sizeof(data)/sizeof(int));
	Solution().longestConsecutive(param);
	return 0;
}

