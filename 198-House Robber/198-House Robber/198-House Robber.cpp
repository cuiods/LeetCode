// 198-House Robber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
		vector<int> data(nums.size()+1, 0);
		data[1] = nums[0];
		for(unsigned int i = 1; i < nums.size(); i++) {
			data[i+1] = max(data[i], nums[i]+data[i-1]);
		}
		return data[nums.size()];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

