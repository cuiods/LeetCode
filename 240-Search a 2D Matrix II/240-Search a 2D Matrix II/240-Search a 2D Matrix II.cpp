// 240-Search a 2D Matrix II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		int m = 0;
		int n = matrix[0].size() - 1;
		while (m < matrix.size() && n >= 0) {
			if (matrix[m][n] > target) n--;
			else if (matrix[m][n] < target) m++;
			else return true;
		}
        return false;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

