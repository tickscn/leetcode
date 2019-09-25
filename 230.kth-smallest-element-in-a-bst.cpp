/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
	int kthSmallest(TreeNode* root, int k)
	{
		int count = 0;
		stack<TreeNode*> St;
		while (root || !St.empty())
		{
			while (root)
			{
				St.push(root);
				root = root->left;
			}
			root = St.top();
			if (k == ++count) return root->val;
			St.pop();
			root = root->right;
		}
		return 0;
	}
};
