// 078-Subsets.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
		vector<vector<int>> result;
		findSub(nums,0,temp,result);
		return result;
    }

	void findSub(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& result) {
		if (index>=nums.size()) {
			result.push_back(temp);
			return;
		}
		temp.push_back(nums[index]);
		findSub(nums,index+1,temp,result);
		temp.pop_back();
		findSub(nums,index+1,temp,result);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

