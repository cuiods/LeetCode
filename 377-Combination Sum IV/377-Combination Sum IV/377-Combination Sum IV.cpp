// 377-Combination Sum IV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target < 0) return 0;
		vector<int> cache(target+1,-1);
		return combinationSum(nums, cache, target);
    }

	int combinationSum(vector<int>& nums, vector<int>& cache, int target) {
		if (cache[target]!=-1) return cache[target];
		int result = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (target - nums[i] == 0) result++;
			else if (target - nums[i] > 0) result += combinationSum(nums, cache, target-nums[i]);
		}
		cache[target] = result;
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

