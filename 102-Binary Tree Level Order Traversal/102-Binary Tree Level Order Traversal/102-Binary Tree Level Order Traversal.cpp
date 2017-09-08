// 102-Binary Tree Level Order Traversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct QNode {
	TreeNode *node;
	int level;
	QNode(TreeNode* n, int l): node(n), level(l) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
		if (root == NULL) return result;
		queue<QNode> que;
		que.push(QNode(root,0));
		while(!que.empty()) {
			QNode qnode = que.front();
			que.pop();
			if(qnode.node->left != NULL) que.push(QNode(qnode.node->left,qnode.level+1));
			if(qnode.node->right != NULL) que.push(QNode(qnode.node->right,qnode.level+1));
			if (result.size() <= qnode.level) result.push_back(vector<int>());
			result[qnode.level].push_back(qnode.node->val);
		}
		return result;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

