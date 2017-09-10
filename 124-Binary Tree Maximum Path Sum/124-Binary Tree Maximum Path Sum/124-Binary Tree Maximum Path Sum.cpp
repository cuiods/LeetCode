// 124-Binary Tree Maximum Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <climits>
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
	int maxSum;
	int maxPathSum(TreeNode* root) {
		maxSum = INT_MIN;
		maxPathSumDown(root);
		return maxSum;
	}

    int maxPathSumDown(TreeNode* root) {
        if (root == NULL) return 0;
		int left = max(0, maxPathSumDown(root->left));
		int right = max(0, maxPathSumDown(root->right));
		maxSum = max(maxSum, left+right+root->val);
		return root->val + max(left, right);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

