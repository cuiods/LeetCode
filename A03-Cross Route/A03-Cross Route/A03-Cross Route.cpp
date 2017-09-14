// A03-Cross Route.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	vector<pair<int,int>> data;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		data.push_back(pair<int,int>(x,y));
	}
	if (data.size() == 0) return 0;
	sort(data.begin(),data.end());
	vector<int> dp(data.size(),1);
	int maxV = 0;
	for (int i = 1; i < dp.size(); i++) {
		int maxIndex = -1;
		for (int j = i-1; j >= 0; j--) {
			if (data[j].second<=data[i].second && (maxIndex<0 || dp[j]>dp[maxIndex])) maxIndex = j;
		}
		if (maxIndex>=0) dp[i]+=dp[maxIndex];
		maxV = max(maxV, dp[i]);
	}
	int res = data.size() - maxV;
	cout << res << endl;
	return 0;
}

