/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
	int findBottomLeftValue(TreeNode* root)
	{
		queue<TreeNode*> Qe;
		Qe.push(root);
		while (!Qe.empty())
		{
			root = Qe.front();
			Qe.pop();
			if (root->right) Qe.push(root->right);
			if (root->left) Qe.push(root->left);
		}
		return root->val;
	}
};
// @lc code=end
