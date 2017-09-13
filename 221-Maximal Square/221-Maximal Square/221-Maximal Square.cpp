// 221-Maximal Square.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		vector<vector<int>> data(matrix.size()+1, vector<int>(matrix[0].size()+1,0));
		int maxLength = 0;
		for (int i = 1; i <= matrix.size(); i++) {
			for (int j = 1; j <= matrix[i-1].size(); j++) {
				if (matrix[i-1][j-1]=='1') {
					data[i][j] = min(min(data[i-1][j], data[i-1][j-1]), data[i][j-1])+1;
					maxLength = max(maxLength, data[i][j]);
				}
			}
		} 
		return maxLength * maxLength;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

