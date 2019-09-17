/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root) return {};
		queue<TreeNode*> Qe;
		vector<vector<int>> res;
		Qe.push(root);
		while (!Qe.empty())
		{
			vector<int> level;
			for (int i = Qe.size(); i > 0; --i)
			{
				TreeNode* pt = Qe.front();
				Qe.pop();
				level.push_back(pt->val);
				if (pt->left) Qe.push(pt->left);
				if (pt->right) Qe.push(pt->right);
			}
			res.push_back(level);
		}
		return res;
	}
};
