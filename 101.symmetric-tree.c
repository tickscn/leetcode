/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p && q)
	{
		if (p->val != q->val)
			return false;
		if (!isSymTree(p->left, q->right))
			return false;
		if (!isSymTree(p->right, q->left))
			return false;
	}
	if ((p && !q) || (!p && q))
		return false;
	return true;
}

bool isSymmetric(struct TreeNode* root)
{
	if (root)
		return isSymTree(root->left, root->right);
	return true;
}
