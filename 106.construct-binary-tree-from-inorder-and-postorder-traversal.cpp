/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inL, int postL, int size)
	{
		if (size == 0) return nullptr;
		TreeNode* head = new TreeNode(postorder[postL + size - 1]);
		int i          = 0;
		while (inorder[i + inL] != postorder[postL + size - 1]) ++i;
		head->left  = buildTree(inorder, postorder, inL, postL, i);
		head->right = buildTree(inorder, postorder, inL + i + 1, postL + i, size - i - 1);
		return head;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int size = inorder.size();
		return buildTree(inorder, postorder, 0, 0, size);
	}
};
