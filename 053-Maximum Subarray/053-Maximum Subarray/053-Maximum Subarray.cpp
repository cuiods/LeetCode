// 053-Maximum Subarray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum = INT_MIN;
		int current = 0;
		for (int i = 0; i < nums.size(); i++) {
			current += nums[i];
			if (current > maxNum) maxNum = current;
			if (current < 0) current = 0;
		}
		return maxNum;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

