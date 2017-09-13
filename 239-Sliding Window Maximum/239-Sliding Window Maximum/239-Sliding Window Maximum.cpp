// 239-Sliding Window Maximum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxIndex;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (!maxIndex.empty() && maxIndex.front() <= i-k) maxIndex.pop_front();
			while (!maxIndex.empty() && nums[maxIndex.back()] <= nums[i]) maxIndex.pop_back();
			maxIndex.push_back(i);
			if (i >= k-1) result.push_back(nums[maxIndex.front()]);
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

