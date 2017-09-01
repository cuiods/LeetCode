// 001-Two Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for(int i = 0; i < nums.size()-1; i++) {
			for (int j = i+1; j < nums.size(); j++) {
				if ((nums[i] + nums[j]) == target) {
					result.push_back(i);
					result.push_back(j);
					break;
				}
			}
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	int myints[] = {2,7,11,15};
	vector<int> parameter (myints, myints + sizeof(myints) / sizeof(int) );
	vector<int> result = solution.twoSum(parameter,9);
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	system("pause");
	return 0;
}

