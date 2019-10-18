/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
	int getMinimumDifference(TreeNode* root)
	{
		int res = INT_MAX, pre = INT_MIN / 2;
		stack<TreeNode*> St;
		while (root || !St.empty())
		{
			while (root)
			{
				St.push(root);
				root = root->left;
			}
			root = St.top();
			St.pop();
			if (root->val - pre < res) res = root->val - pre;
			pre  = root->val;
			root = root->right;
		}
		return res;
	}
};
// @lc code=end
