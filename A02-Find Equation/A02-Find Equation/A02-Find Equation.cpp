// A02-Find Equation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(vector<int>& nums,vector<pair<string,int>>& res,int target,string path,int current,int start) {
	if (start == nums.size()) {
		if (current >= target) res.push_back(pair<string,int>(path, current));
		return;
	}
	if (current == 0) helper(nums, res, target, to_string(nums[start]), nums[start], start+1);
	else {
		helper(nums,res,target, path+"+"+to_string(nums[start]), current+nums[start], start+1);
		helper(nums,res,target, path+"*"+to_string(nums[start]), current*nums[start], start+1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,target;
	cin >> n >> target;
	vector<int> nums(n,0);
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
	vector<pair<string,int>> res;
	helper(nums,res,target,"",0,0);
	if (res.size() == 1) cout << res[0].first << endl;
	else if (res.size() > 1){
		int minIndex = 0;
		for (int i = 1; i < res.size(); i++) {
			if (res[i].second < res[minIndex].second) minIndex = i;
		}
		cout << res[minIndex].first << endl;
	}
	return 0;
}

