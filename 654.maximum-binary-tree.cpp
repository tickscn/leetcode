/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums)
	{
		TreeNode* root = nullptr;
		int pre        = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			TreeNode* subroot = root;
			TreeNode* node    = new TreeNode(nums[i]);
			if (nums[i] > pre)
			{
				node->left = root;
				root       = node;
			}
			else
			{
				while (subroot->right)
				{
					if (nums[i] > subroot->right->val)
					{
						node->left     = subroot->right;
						subroot->right = node;
						break;
					}
					subroot = subroot->right;
				}
				if (!subroot->right)
				{
					subroot->right = node;
				}
			}
			pre = root->val;
		}
		return root;
	}
};
// @lc code=end
