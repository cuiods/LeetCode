// 283-Move Zeroes.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
		int fast = 0;
		for (; fast < nums.size(); fast++) {
			if (nums[fast]!=0) {
				if (slow!=fast) nums[slow] = nums[fast];
				slow++;
			}
		}
		while (slow < nums.size()) nums[slow++] = 0;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
