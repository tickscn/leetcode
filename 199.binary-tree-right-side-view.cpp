/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> Qe;
		Qe.push(root);
		while (!Qe.empty())
		{
			res.push_back(Qe.back()->val);
			for (int size = Qe.size(); size > 0; --size)
			{
				TreeNode* pt = Qe.front();
				Qe.pop();
				if (pt->left) Qe.push(pt->left);
				if (pt->right) Qe.push(pt->right);
			}
		}
		return res;
	}
};
