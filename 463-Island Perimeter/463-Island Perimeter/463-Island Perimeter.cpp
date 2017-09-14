// 463-Island Perimeter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		int result = 0;
		if (grid.size() == 0) return result;
		for (unsigned int i = 0; i < grid.size(); i++) {
			for (unsigned int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					helper(grid,i,j,result);
					break;
				}
			}
		}
		return result;
    }

	void helper(vector<vector<int>>& grid, int x, int y, int& result) {
		if (grid[x][y] != 1) return;
		grid[x][y] = 2;
		if (x-1>=0) {
			if (grid[x-1][y] == 1) helper(grid, x-1, y, result);
			else if (grid[x-1][y] == 0) result++;
		} else result++;
		if (x+1<grid.size()) {
			if (grid[x+1][y] == 1) helper(grid, x+1, y, result);
			else if (grid[x+1][y] == 0) result++;
		} else result++;
		if (y-1>=0) {
			if (grid[x][y-1] == 1) helper(grid, x, y-1, result);
			else if (grid[x][y-1] == 0) result++;
		} else result++;
		if (y+1<grid[0].size()) {
			if (grid[x][y+1] == 1) helper(grid, x, y+1, result);
			else if (grid[x][y+1] == 0) result++;
		} else result++;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

