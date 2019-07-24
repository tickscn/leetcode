/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * 	int val;
 * 	TreeNode* left;
 * 	TreeNode* right;
 * 	TreeNode(int x)
 * 	    : val(x)
 * 	    , left(nullptr)
 * 	    , right(nullptr)
 * 	{
 * 	}
 * };
 */
class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;
		TreeNode* cur = root;
		while (cur)
		{
			if (!cur->left)
			{
				if (pre && pre->val > cur->val)
				{
					if (!first) first = pre;
					second = cur;
				}
				pre = cur;
				cur = cur->right;
			}
			else
			{
				TreeNode* tmp = cur->left;
				while (tmp->right && tmp->right != cur) tmp = tmp->right;
				if (!tmp->right)
				{
					tmp->right = cur;
					cur        = cur->left;
				}
				else
				{
					tmp->right = nullptr;
					if (pre && pre->val > cur->val)
					{
						if (!first) first = pre;
						second = cur;
					}
					pre = cur;
					cur = cur->right;
				}
			}
		}
		int tmp     = first->val;
		first->val  = second->val;
		second->val = tmp;
	}
};
