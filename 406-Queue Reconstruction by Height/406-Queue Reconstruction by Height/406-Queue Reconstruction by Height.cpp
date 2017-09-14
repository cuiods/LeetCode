// 406-Queue Reconstruction by Height.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <queue>
using namespace std;

struct mcmp{
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.first == p2.first? p1.second > p2.second : p1.first < p2.first;
	}
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		priority_queue<pair<int, int>,vector<pair<int, int>>,mcmp> que;
		for (auto c: people) que.push(c);
		vector<pair<int, int>> result;
		while (!que.empty()) {
			pair<int,int> current = que.top();
			que.pop();
			result.insert(result.begin()+current.second, current);
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<pair<int, int>> people;
	people.push_back(pair<int,int>(7,0));
	people.push_back(pair<int,int>(4,4));
	people.push_back(pair<int,int>(7,1));
	people.push_back(pair<int,int>(5,0));
	people.push_back(pair<int,int>(6,1));
	people.push_back(pair<int,int>(5,2));
	Solution().reconstructQueue(people);
	return 0;
}

