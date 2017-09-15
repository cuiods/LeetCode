// B02-Graph Minimum Distance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	int n;
	cin >> n;
	int nodeNum = 0;
	map<int,int> nodemap;
	map<pair<int,int>,int> dismap;
	for (int i = 0; i < n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if (nodemap.find(a)==nodemap.end()) nodemap[a] = nodeNum++;
		if (nodemap.find(b)==nodemap.end()) nodemap[b] = nodeNum++;
		dismap[pair<int,int>(nodemap[a],nodemap[b])] = c;
	}
	int A,B;
	cin >> A >> B;
	vector<vector<int>> graph(nodeNum, vector<int>(nodeNum, 10000000));
	for (map<pair<int,int>,int>::iterator it = dismap.begin();it!=dismap.end();it++) {
		graph[it->first.first][it->first.second] = it->second;
		graph[it->first.second][it->first.first] = it->second;
	}
	for (int k = 0; k < nodeNum; k++) {
		for (int i = 0; i < nodeNum; i++) {
			for (int j = 0; j < nodeNum; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}
	cout << graph[nodemap[A]][nodemap[B]] << endl;
	vector<int> d(nodeNum,INT_MAX);
	d[nodemap[B]] = 0;
	for (int i = 0; i < nodeNum; i++) {
		int minIndex = 0;
		for (int j = 0; j < nodeNum; j++) 
			if(d[j]<d[minIndex]) minIndex = j;
		for (int j = 0; j < nodeNum; j++) 
			if(graph[minIndex][j]<10000000) 
				d[j] = min(d[j],graph[minIndex][j]+d[minIndex]);
	}
	cout << d[nodemap[A]] << endl;
	return 0;
}

