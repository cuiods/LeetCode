// 034-Search for a Range.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
		if (nums.size()==0) return result;
		int left = 0, right = nums.size()-1;
		while(left<right) {
			int middle = (left+right)/2;
			if(nums[middle]<target) left = middle+1;
			else right = middle;
		}
		if (nums[left]!=target) return result;
		result[0] = left;
		right = nums.size()-1;
		while(left<right) {
			int middle = (left+right)/2 + 1;
			if(nums[middle]>target) right = middle-1;
			else left = middle;
		}
		result[1] = right;
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

