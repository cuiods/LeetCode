// 075-Sort Colors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
		int a=0, b=0, c=0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]==0) {
				nums[c++]=2; nums[b++]=1; nums[a++]=0;
			} else if (nums[i]==1) {
				nums[c++]=2; nums[b++]=1;
			} else nums[c++]=2;
		}
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

