// 015-3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int length = nums.size();
		for (int i = 0; i < length-2; i++) {
			if (i==0 || (i>0 && nums[i] != nums[i-1])) {
				int left = i+1;
				int right = length-1;
				int sum = 0-nums[i];
				while (left < right) {
					int sumTemp = nums[left]+nums[right];
					if(sumTemp==sum) {
						vector<int> items;
						items.push_back(nums[i]);
						items.push_back(nums[left]);
						items.push_back(nums[right]);
						result.push_back(items);
						while (left < right && nums[left]==nums[left+1]) left++;
						while (left < right && nums[right]==nums[right-1]) right--;
						left ++;
						right --;
					} else if (sumTemp < sum) left++;
					else right--;
				}
			}
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

