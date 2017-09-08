// 098-Validate Binary Search Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
    }

	bool isValidBST(TreeNode* root, int min, int max) {
		if (root == NULL) return true;
		if (root->val < min || root->val > max) return false;
		if (root->left != NULL && (root->val==INT_MIN||!isValidBST(root->left, min, root->val-1))) return false;
		if (root->right != NULL && (root->val==INT_MAX||!isValidBST(root->right, root->val+1, max))) return false;
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

