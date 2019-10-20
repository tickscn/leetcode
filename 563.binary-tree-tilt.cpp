/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
	int findTilt(TreeNode* root)
	{
		int res = 0;
		sum(root, res);
		return res;
	}
	int sum(TreeNode* root, int& res)
	{
		if (!root) return 0;
		int left  = sum(root->left, res);
		int right = sum(root->right, res);
		res += abs(left - right);
		return left + right + root->val;
	}
};
// @lc code=end
