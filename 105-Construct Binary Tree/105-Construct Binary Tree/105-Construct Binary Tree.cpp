// 105-Construct Binary Tree.cpp : 定义控制台应用程序的入口点。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		return buildTree(preorder,0,preorder.size(), inorder,0,inorder.size()-1);
    }

	TreeNode* buildTree(vector<int>& preorder, unsigned int ps,unsigned int pe, vector<int>& inorder, unsigned int is, unsigned int ie) {
		TreeNode* node = new TreeNode(preorder[ps]);
		unsigned int iindex = is;
		for(; iindex <= ie; iindex++) if(inorder[iindex]==preorder[ps]) break;
		if (ps+1 <= ps+(iindex-is) && ps+(iindex-is) < preorder.size() && iindex-1>=is) 
			node->left = buildTree(preorder, ps+1, ps+(iindex-is), inorder,is, iindex-1);
		if (ps+(iindex-is)+1 <= pe && iindex+1 <= ie) 
			node->right = buildTree(preorder, ps+(iindex-is)+1, pe,inorder, iindex+1, ie);
		return node;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

