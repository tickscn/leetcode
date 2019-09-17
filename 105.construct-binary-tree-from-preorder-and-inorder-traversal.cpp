/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	TreeNode* buildTree(vector<int>& pre, vector<int>& in, int pL, int iL, int size)
	{
		if (size < 1) return nullptr;
		TreeNode* head = new TreeNode(pre[pL]);

		int i = 0;
		while (pre[pL] != in[iL + i]) ++i;
		head->left  = buildTree(pre, in, pL + 1, iL, i);
		head->right = buildTree(pre, in, pL + i + 1, iL + i + 1, size - i - 1);
		return head;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0) return nullptr;
		TreeNode* head = new TreeNode(preorder[0]);

		int i = 0;
		while (preorder[0] != inorder[i]) ++i;
		head->left  = buildTree(preorder, inorder, 1, 0, i);
		head->right = buildTree(preorder, inorder, i + 1, i + 1, preorder.size() - i - 1);
		return head;
	}
};
