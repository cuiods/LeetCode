// 046-Permutations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
		vector<int> temp;
		permute(nums,temp,result);
		return result;
    }

	void permute(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
		if (nums.size() == 0) result.push_back(temp);
		for(int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			temp.push_back(num);
			nums.erase(nums.begin()+i);
			permute(nums,temp,result);
			nums.insert(nums.begin()+i,num);
			temp.pop_back();
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

