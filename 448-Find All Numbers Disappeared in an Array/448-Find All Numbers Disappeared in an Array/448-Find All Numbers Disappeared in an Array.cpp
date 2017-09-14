// 448-Find All Numbers Disappeared in an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (unsigned int i = 0; i < nums.size(); i++) {
			int temp = abs(nums[i])-1;
			if (nums[temp]>0) nums[temp] = -nums[temp];
		}
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]>0) res.push_back(i+1);
		}
		return res;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

