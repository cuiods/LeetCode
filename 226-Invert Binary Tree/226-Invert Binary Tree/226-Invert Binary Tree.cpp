// 226-Invert Binary Tree.cpp : 定义控制台应用程序的入口点。
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
    TreeNode* invertTree(TreeNode* root) {
       if(root == NULL) return NULL;
	   TreeNode *temp = root->left;
	   root->left = root->right;
	   root->right = temp;
	   invertTree(root->left);
	   invertTree(root->right);
	   return root;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

