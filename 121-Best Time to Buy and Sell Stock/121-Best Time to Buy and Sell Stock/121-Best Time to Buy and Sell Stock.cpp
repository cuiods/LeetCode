// 121-Best Time to Buy and Sell Stock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
        int minValue = INT_MAX;
		int maxPro = 0;
		for (unsigned int i = 0; i < prices.size(); i++) {
			int price = prices[i];
			if (price < minValue) minValue = price;
			else if (price-minValue > maxPro) maxPro = price-minValue;
		}
		return maxPro;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

