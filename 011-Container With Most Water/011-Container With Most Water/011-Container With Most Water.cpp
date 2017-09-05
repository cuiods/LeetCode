// 010-Container With Most Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
		int i = 0, j = height.size()-1;
		while (i < j) {
			int h = min(height[i], height[j]);
			result = max(result, (j-i)*h);
			while(height[j]<=h && i < j) j--;
			while(height[i]<=h && i < j) i++;
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

