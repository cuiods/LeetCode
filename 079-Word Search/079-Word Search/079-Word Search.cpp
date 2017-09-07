// 079-Word Search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (exist(board,word,0,i,j)) return true;
			}
		}
		return false;
    }

	bool exist(vector<vector<char>>& board, string word, int index, int x, int y) {
		if (index == word.length()) return true;
		if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) return false;
		if (board[x][y]!=word[index]) return false;
		char temp = board[x][y];
		board[x][y] = 0;
		bool result = exist(board,word,index+1,x+1,y) || exist(board,word,index+1,x,y+1)
			|| exist(board,word,index+1,x-1,y) || exist(board,word,index+1,x,y-1);
		board[x][y] = temp;
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

