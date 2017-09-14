// 437-Path Sum III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
		findPath(root, sum, false, res);
		return res;
    }

	void findPath(TreeNode* root, int sum, bool isStart, int& res) {
		if (root == NULL) return;
		if (root->val == sum) res++;
		int next = sum - root->val;
		if (!isStart) {
			findPath(root->left, sum, false, res);
			findPath(root->right, sum, false, res);
		}
		findPath(root->left, next, true, res);
		findPath(root->right, next, true, res);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

