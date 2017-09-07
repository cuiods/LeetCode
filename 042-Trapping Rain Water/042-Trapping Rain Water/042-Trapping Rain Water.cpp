// 042-Trapping Rain Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int size = height.size();
		if (size == 0) return 0;
		vector<int> left_max(size);
		vector<int> right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; i++) {
			left_max[i] = max(left_max[i-1],height[i]);
		}
		right_max[size-1] = height[size-1];
		for (int j = size-2; j>=0; j--) {
			right_max[j] = max(right_max[j+1], height[j]);
		}
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += min(left_max[i],right_max[i]) - height[i];
		}
		return sum;
    }

	/*int trap(vector<int>& height) {
		int total = 0;
		while (true) {
			int start = -1;
			bool next = false;
			for (unsigned int i = 0; i < height.size(); i++) {
				if(height[i] == 0) continue;
				if(start != -1) {
					total += i-start-1;
					next = true;
				}
				start = i;
				height[i]--;
			}
			if (!next) break;
		}
		return total;
    }*/
};



int _tmain(int argc, _TCHAR* argv[])
{
	int myints[3] = {2,0,2};
	vector<int> height(myints, myints+3);
	Solution().trap(height);
	return 0;
}

