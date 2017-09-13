// 238-Product of Array Except Self.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
		for (int i = 1; i < nums.size(); i++) {
			result[i] = nums[i-1]*result[i-1];
		}
		int right = 1;
		for (int i = nums.size()-1; i>=0; i--) {
			result[i] *= right;
			right *= nums[i];
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

