// 337-House Robber III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
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
    int rob(TreeNode* root) {
		vector<int> data = robSub(root);
		return max(data[0],data[1]);
    }

	vector<int> robSub(TreeNode* root) {
		if (root == NULL) return vector<int>(2,0);
		vector<int> result(2,0);
		vector<int> left = robSub(root->left);
		vector<int> right = robSub(root->right);
		result[0] = root->val + left[1] + right[1];
		result[1] = max(left[0],left[1])+max(right[0], right[1]);
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

