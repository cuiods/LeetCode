// A01-Virus Infection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int m,n,k;
	cin >> n >> m >> k;
	if (n<=0 || n >= 10 || m <= 0 || m >= 10 || k <= 0 || k >= n*m) {
		cout << 0; return 0;
	}
	vector<vector<int>> data(n, vector<int>(m,0));
	queue<pair<int,int>> que;
	int maxNum = 0;
	for (int i = 0; i < k; i++) {
		int a,b;
		cin >> a >> b;
		if (a-1 >= 0 && a-1 < n && b-1 >= 0 && b-1 < m) data[a-1][b-1] = 1;
		que.push(pair<int,int>(a-1,b-1));
	}
	while (!que.empty()) {
		pair<int,int> current = que.front();
		que.pop();
		int& state = data[current.first][current.second];
		state++;
		if (state <= 5) { 
			if (state >= 4) {
				if (current.first-1>=0 && data[current.first-1][current.second]==0) {
					data[current.first-1][current.second]++;
					que.push(pair<int,int>(current.first-1,current.second));
				}
				if (current.first+1<n && data[current.first+1][current.second]==0) {
					data[current.first+1][current.second]++;
					que.push(pair<int,int>(current.first+1,current.second));
				}
				if (current.second-1>=0 && data[current.first][current.second-1]==0) {
					data[current.first][current.second-1]++;
					que.push(pair<int,int>(current.first,current.second-1));
				}
				if (current.second+1<m && data[current.first][current.second+1]==0) {
					data[current.first][current.second+1]++;
					que.push(pair<int,int>(current.first,current.second+1));
				}
			}
			que.push(current);
		}
		else if (state == 6) state = -1;
		int curNum = que.size();
		maxNum = max(maxNum,curNum);
	}
	cout<<maxNum<<endl;
	return 0;
}

