// 033-Search in Rotated Sorted Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
		int last = nums.size()-1;
		int end = nums.size()-1;
		int result = -1;
		while(start <= end) {
			int middle = (start+end)/2;
			if (nums[middle] == target) {
				result = middle; break;
			} else if (nums[middle] > target) {
				if (nums[middle]<=nums[last] || target>=nums[0]) end = middle-1;
				else start = middle+1;
			} else {
				if (nums[middle]>=nums[0] || target<=nums[last]) start = middle+1;
				else end = middle-1;
			}
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

