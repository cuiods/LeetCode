// 236-Lowest Common Ancestor of a Binary Tree.cpp : 定义控制台应用程序的入口点。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return !left?right: !right? left: root;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

