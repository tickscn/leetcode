/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		TreeNode* p = nullptr;
		TreeNode* z = root;
		while (z)
		{
			if (key == z->val) return deleteNode(root, z, p);
			p = z;
			if (key < z->val)
				z = z->left;
			else
				z = z->right;
		}
		return root;
	}

private:
	TreeNode* transSubtree(TreeNode* src, TreeNode* dst, TreeNode* p, TreeNode* root)
	{
		if (!p) return dst;
		if (src == p->left)
			p->left = dst;
		else
			p->right = dst;
		return root;
	}
	TreeNode* deleteNode(TreeNode* root, TreeNode* z, TreeNode* p)
	{
		if (!z->left)
		{
			root = transSubtree(z, z->right, p, root);
		}
		else if (!z->right)
		{
			root = transSubtree(z, z->left, p, root);
		}
		else
		{
			TreeNode* yp = z;
			TreeNode* y  = z->right;
			while (y->left)
			{
				yp = y;
				y  = y->left;
			}
			TreeNode* x = y->right;
			if (yp != z)
			{
				root     = transSubtree(y, x, yp, root);
				y->right = z->right;
			}
			root    = transSubtree(z, y, p, root);
			y->left = z->left;
			delete z;
		}
		return root;
	}
};
// @lc code=end
