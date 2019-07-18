/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (!root) return {};
		stack<TreeNode*> St;
		vector<int> res;
		while (root || !St.empty())
		{
			while (root)
			{
				St.push(root);
				root = root->left;
			}
			root = St.top();
			St.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};
