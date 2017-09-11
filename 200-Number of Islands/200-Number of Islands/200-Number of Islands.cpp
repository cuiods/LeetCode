// 200-Number of Islands.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '1') {
					count++;
					numIslandsFinder(i,j,grid);
				}
			}
		}
		return count;
    }

	void numIslandsFinder(int x, int y, vector<vector<char>>& grid) {
		grid[x][y] = '2';
		if (x-1>=0 && grid[x-1][y]=='1') numIslandsFinder(x-1,y,grid);
		if (y-1>=0 && grid[x][y-1]=='1') numIslandsFinder(x,y-1,grid);
		if (x+1<grid.size() && grid[x+1][y]=='1') numIslandsFinder(x+1,y,grid);
		if (y+1<grid[x].size() && grid[x][y+1]=='1') numIslandsFinder(x,y+1,grid);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

