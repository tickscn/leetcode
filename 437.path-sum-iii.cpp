/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
	int pathSum(TreeNode* root, int sum)
	{
		if (!root) return 0;
		return preSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

private:
	int preSum(TreeNode* root, int pre, int sum)
	{
		if (!root) return 0;
		int cur = pre + root->val;
		return preSum(root->left, cur, sum) + preSum(root->right, cur, sum) + (cur == sum ? 1 : 0);
	}
};
// @lc code=end
