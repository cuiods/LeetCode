// 062-Unique Paths.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n,1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				paths[i][j] = paths[i-1][j]+paths[i][j-1];
			}
		}
		return paths[m-1][n-1];
    }
};

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        int count = 0;
//		findPath(1,1,m,n,count);
//		return count;
//    }
//
//	void findPath(int x, int y, int m, int n, int& count) {
//		if (x == m && y == n) {
//			count++;
//			return;
//		}
//		if (x+1 <= m) findPath(x+1,y,m,n,count);
//		if (y+1 <= n) findPath(x,y+1,m,n,count);
//	}
//};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

