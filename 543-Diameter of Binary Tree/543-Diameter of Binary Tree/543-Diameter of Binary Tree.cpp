// 543-Diameter of Binary Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return 0;
		vector<int> res = helper(root);
		return max(res[0],res[1])-1;
    }

	vector<int> helper(TreeNode* root) {
		vector<int> res(3,0);
		if (root == NULL) return res;
		vector<int> left = helper(root->left);
		vector<int> right = helper(root->right);
		res[0] = max(max(left[1],left[0]),max(right[1],right[0]));
		res[1] = left[2]+1+right[2];
		res[2] = 1+max(left[2],right[2]);
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

