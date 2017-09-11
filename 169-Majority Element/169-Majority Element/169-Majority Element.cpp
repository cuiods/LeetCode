// 169-Majority Element.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
		int major = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (count == 0) major = nums[i];
			if (major == nums[i]) count++;
			else count--;
		}
		return major;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

