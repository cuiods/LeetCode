// 207-Course Schedule.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		queue<int> studyQueue;
		map<int,vector<int>> prereq;
		vector<int> inDegree(numCourses,0);
		for (int i = 0; i < prerequisites.size(); i++) {
			inDegree[prerequisites[i].first]++;
			if(prereq.find(prerequisites[i].second)==prereq.end()) 
				prereq[prerequisites[i].second] = vector<int>();
			prereq[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		for (int i = 0; i < inDegree.size(); i++) if(inDegree[i]==0) studyQueue.push(i);
		while(!studyQueue.empty()) {
			int current = studyQueue.front();
			studyQueue.pop();
			if (prereq.find(current)==prereq.end()) continue;
			vector<int> deps = prereq[current];
			for (int i = 0; i < deps.size(); i++) {
				inDegree[deps[i]]--;
				if (inDegree[deps[i]]==0) studyQueue.push(deps[i]);
			}
		}
		for (int i = 0; i < inDegree.size(); i++) if (inDegree[i]>0) return false;
		return true;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

