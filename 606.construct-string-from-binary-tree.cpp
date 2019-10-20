/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
	string tree2str(TreeNode* t)
	{
		if (!t) return "";
		if (!t->left && !t->right)
		{
			return to_string(t->val);
		}
		if (t->left && !t->right)
		{
			return to_string(t->val) + "(" + tree2str(t->left) + ")";
		}
		if (!t->left && t->right)
		{
			return to_string(t->val) + "()" + "(" + tree2str(t->right) + ")";
		}
		return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
	}
};
// @lc code=end
