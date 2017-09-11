// 136-Single Number.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int result = nums[0];
		for (unsigned int i = 1; i < nums.size(); i++) {
			result ^= nums[i];
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

