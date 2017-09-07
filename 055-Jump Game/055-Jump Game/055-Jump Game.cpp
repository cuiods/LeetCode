// 055-Jump Game.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxNum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i > maxNum) return false;
			maxNum = max(i+nums[i], maxNum);
		}
		return true;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

