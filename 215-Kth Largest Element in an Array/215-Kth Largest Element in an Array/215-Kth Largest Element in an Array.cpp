// 215-Kth Largest Element in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
		int start = 0;
		int end = nums.size()-1;
		while (start <= end) {
			int p = partition(nums, start, end);
			if (p < k) start = p + 1;
			else if (p > k) end = p - 1;
			else break;
		}
		return nums[k];
    }

	int partition(vector<int>& nums, int start, int end) {
		if (start == end) return start;
		int i = start;
		int j = end+1;
		while (i < j) {
			while (i <= end && nums[++i] < nums[start]);
			while (j >= start && nums[--j] > nums[start]);
			if(i>=j) break;
			swap(nums[i], nums[j]);
		}
		swap(nums[start],nums[j]);
		return j;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int nums[6] = {3,2,1,5,6,4};
	vector<int> param(nums, nums+sizeof(nums)/sizeof(int));
	Solution().findKthLargest(param,2);
	return 0;
}

