// 084-Largest Rectangle in Histogram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> vstack;
		int maxSize = 0;
		unsigned int i = 0;
		for (; i < heights.size(); i++) {
			if (vstack.empty() || heights[i] > heights[vstack.back()]) {
				vstack.push_back(i);
				continue;
			} else while(!vstack.empty() && heights[i] <= heights[vstack.back()]) {
				int current = vstack.back();
				vstack.pop_back();
				int left = vstack.empty()? -1: vstack.back();
				int size = (i-left-1) * heights[current];
				if (size > maxSize) maxSize = size;
			}
			vstack.push_back(i);
		}
		while(!vstack.empty()) {
			int current = vstack.back();
			vstack.pop_back();
			int left = vstack.empty()? -1: vstack.back();
			int size = (i-left-1) * heights[current];
			if (size > maxSize) maxSize = size;
		}
		return maxSize;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int data[6] = {2,1,5,6,2,3};
	vector<int> param(data, data+6);
	Solution().largestRectangleArea(param);
	return 0;
}

