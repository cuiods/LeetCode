// 085-Maximal Rectangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		vector<int> height(matrix[0].size()+1,0);
		int maxSize = 0;
		for (unsigned int i = 0; i < matrix.size(); i++) {
			vector<int> vstack;
			for (unsigned int j = 0; j <= matrix[i].size(); j++) {
				if(j<matrix[i].size() && matrix[i][j]=='1') height[j]++;
				else height[j] = 0;
				if (vstack.empty() || height[vstack.back()] <= height[j]) vstack.push_back(j);
				else {
					while (!vstack.empty() && height[vstack.back()] > height[j]) {
						int current = vstack.back();
						vstack.pop_back();
						int size = height[current] * (vstack.empty()?j:j-vstack.back()-1);
						if (size > maxSize) maxSize = size; 
					}
					vstack.push_back(j);
				}
			}
		}
		return maxSize;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

