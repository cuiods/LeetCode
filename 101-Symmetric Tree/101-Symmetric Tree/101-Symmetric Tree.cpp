// 101-Symmetric Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root==NULL) return true;
		return isSymmetric(root->left, root->right);
    }

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (left == NULL || right == NULL) return left==right;
		if (left->val != right->val) return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

