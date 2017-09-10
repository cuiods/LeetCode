// 104-Maximum Depth of Binary Tree.cpp : 定义控制台应用程序的入口点。
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
    int maxDepth(TreeNode* root) {
		int max = 0;
		maxDepth(root, 1, max);
		return max;
    }

	void maxDepth(TreeNode* root, int current, int& max) {
		if (root == NULL) return;
		if (current > max) max = current;
		if (root->left != NULL) maxDepth(root->left, current+1, max);
		if (root->right != NULL) maxDepth(root->right, current+1, max);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

