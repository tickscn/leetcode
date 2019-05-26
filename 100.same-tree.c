/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p && q)
	{
		if (p->val != q->val)
			return false;
		if (!isSameTree(p->left, q->left))
			return false;
		if (!isSameTree(p->right, q->right))
			return false;
	}
	if ((p && !q) || (!p && q))
		return false;
	return true;
}
