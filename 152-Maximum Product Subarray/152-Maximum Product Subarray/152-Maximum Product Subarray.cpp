// 152-Maximum Product Subarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mi = nums[0];
		int ma = nums[0];
		int maxNum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int current = nums[i];
			if (current < 0) swap(mi,ma);
			mi = min(current*mi, current);
			ma = max(current*ma, current);
			maxNum = max(maxNum, ma);
		}
		return maxNum;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

