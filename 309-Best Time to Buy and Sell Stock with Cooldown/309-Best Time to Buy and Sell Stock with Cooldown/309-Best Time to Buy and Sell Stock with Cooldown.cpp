// 309-Best Time to Buy and Sell Stock with Cooldown.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1) return 0;
        vector<int> buy(n+1,INT_MIN);
		vector<int> sell(n+1,0);
		for (int i = 1; i < n+1; i++) {
			buy[i] = max((i-2>=0?sell[i-2]:0)-prices[i-1], buy[i-1]);
			sell[i] = max(buy[i-1]+prices[i-1], sell[i-1]);
		}
		return sell[n];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

