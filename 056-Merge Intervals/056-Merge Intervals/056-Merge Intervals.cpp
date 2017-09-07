// 056-Merge Intervals.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b) {
	return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		vector<Interval> result;
		int end = INT_MIN;
		for (unsigned int i = 0; i < intervals.size(); i++) {
			Interval temp = intervals[i];
			if (temp.start <= end && i > 0)
				result.back().end = max(result.back().end, temp.end);
			else result.push_back(temp);
			end = result.back().end;
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

