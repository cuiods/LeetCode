// B03-Operation Target.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& nums, int& result, double target, int start, double current, double multi) {
	if (result) return;
	if (start == nums.size()) {
		if (abs(current - target)<0.0000001) result = 1;
		return;
	}
	if (start == 0) helper(nums,result,target,start+1,nums[start],nums[start]);
	else {
		helper(nums,result,target,start+1,current+nums[start],nums[start]);
		helper(nums,result,target,start+1,current-nums[start],-nums[start]);
		helper(nums,result,target,start+1,current-multi+multi*nums[start],multi*nums[start]);
		if (nums[start]!=0) 
			helper(nums,result,target,start+1,current-multi+multi/nums[start],multi/nums[start]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	vector<int> nums(n,0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	int target;
	cin >> target;
	int result = 0;
	helper(nums,result,target,0,0,0);
	cout << result << endl;
	return 0;
}

