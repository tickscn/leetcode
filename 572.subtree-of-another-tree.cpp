/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
	bool isSubtree(TreeNode* s, TreeNode* t)
	{
		if (!s && !t) return true;
		if (!s || !t) return false;
		if (isEqualTree(s, t)) return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	bool isEqualTree(TreeNode* s, TreeNode* t)
	{
		if (!s && !t) return true;
		if (!s || !t) return false;
		if (s->val != t->val) return false;
		return isEqualTree(s->left, t->left) && isEqualTree(s->right, t->right);
	}
};
// @lc code=end
