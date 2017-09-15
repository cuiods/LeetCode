// 565-Array Nesting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxNum = 0;
		for (int i = 0; i < nums.size(); i++) {
			int current = 0;
			if (nums[i]<nums.size()) helper(nums, current, i);
			if (current > maxNum) maxNum = current;
		}
		return maxNum;
    }

	void helper(vector<int>& nums, int& res, int index) {
		if (nums[index]<nums.size()) {
			res++;
			int temp = nums[index];
			nums[index] = nums.size();
			helper(nums,res,temp);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

