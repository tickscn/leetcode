/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		if (!root) return {};
		vector<vector<int>> st;
		queue<TreeNode*> Qe;
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
			st.push_back(level);
		}
		vector<vector<int>> res(st.size());
		for (int i = 0; i < st.size(); ++i)
		{
			res[i] = st[st.size() - 1 - i];
		}
		return res;
	}
};
