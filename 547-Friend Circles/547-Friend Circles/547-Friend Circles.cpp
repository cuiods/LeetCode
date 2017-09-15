// 547-Friend Circles.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[0].size(); j++) {
				if (M[i][j]==1) {
					res++;
					dfs(M,i);
					break;
				}
			}
		}
		return res;
    }

	void dfs(vector<vector<int>>& M,int x) {
		for (int i = 0; i < M[x].size(); i++) {
			if (M[x][i]==1) {
				M[x][i] = 2;
				M[i][x] = 2;
				if (x!=i) dfs(M,i);
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

