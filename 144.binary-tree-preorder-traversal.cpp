/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> St;
		while (root || !St.empty())
		{
			while (root)
			{
				res.push_back(root->val);
				St.push(root);
				root = root->left;
			}
			root = St.top();
			St.pop();
			root = root->right;
		}
		return res;
	}
};
