// B01-Integer Cube.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string input;
	cin >> input;
	int len = input.length();
	vector<int> number(len,0);
	for (int i = len-1; i>=0; i--) number[len-i-1] = input[i]-'0';
	vector<int> res(3*len,0);
	vector<int> carry(3*len,0);
	for (int i = 0; i < len; i++) res[i] = number[i];
	for (int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < carry.size();j++) carry[j] = 0;
		int j = 0;
		for (j = 0; j < 3*len; j++) {
			vector<int> tresult(len+1,0);
			int c = 0;
			for (int k = 0; k < len; k++) {
				int temp = res[j]*number[k]+c;
				tresult[k] = temp%10;
				c = temp/10;
				if (k == len-1 && c) tresult[k+1] = c;
			}
			c = 0;
			for (int k = 0; k < len+1; k++) {
				if (j+k+1 >= 3*len) break;
				int temp = carry[j+k] + tresult[k] + c;
				carry[j+k] = temp%10;
				c = temp/10;
				if (k == len && c) carry[j+k+1] = c;
			}
		}
		for (int j = 0; j < 3*len; j++) res[j] = carry[j];
	}
	int iout;
	for (iout = 3*len-1; res[iout]==0; iout--);
	while (iout>=0) cout << res[iout--];
	cout << endl;
	return 0;
}

