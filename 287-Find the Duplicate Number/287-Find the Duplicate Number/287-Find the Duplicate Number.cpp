// 287-Find the Duplicate Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size()<2) return -1;
		int slow = nums[0];
		int fast = nums[nums[0]];
		while(slow!=fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

