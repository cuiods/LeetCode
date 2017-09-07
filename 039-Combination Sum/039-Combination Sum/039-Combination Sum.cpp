// 039-Combination Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> current;
		vector<vector<int>> result;
		combinationSum(candidates, current, target, result);
		return result;
    }

	void combinationSum(vector<int>& candidates, vector<int>& current, int target, vector<vector<int>>& result) {
		if (target < 0) return;
		if (target == 0) result.push_back(current);
		for (int i = 0; i < candidates.size(); i++) {
			if (current.size() > 0 && current.back() > candidates[i]) continue;
			current.push_back(candidates[i]);
			combinationSum(candidates, current, target-candidates[i], result);
			current.pop_back();
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

