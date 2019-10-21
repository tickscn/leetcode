/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 */

// @lc code=start
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
	TreeNode* addOneRow(TreeNode* root, int v, int d)
	{
		if (d == 1)
		{
			TreeNode* node = new TreeNode(v);
			node->left     = root;
			return node;
		}
		queue<TreeNode*> Qe;
		Qe.push(root);
		while (d > 2)
		{
			for (int i = Qe.size(); i > 0; --i)
			{
				TreeNode* pt = Qe.front();
				Qe.pop();
				if (pt->left) Qe.push(pt->left);
				if (pt->right) Qe.push(pt->right);
			}
			--d;
		}
		while (!Qe.empty())
		{
			TreeNode* pt = Qe.front();
			Qe.pop();
			TreeNode* node = new TreeNode(v);
			node->left     = pt->left;
			pt->left       = node;
			node           = new TreeNode(v);
			node->right    = pt->right;
			pt->right      = node;
		}
		return root;
	}
};
// @lc code=end
