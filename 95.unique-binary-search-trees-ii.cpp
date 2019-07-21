/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */
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
	vector<TreeNode*> generateSubTrees(int low, int high)
	{
		vector<TreeNode*> ret;
		if (low > high) return {nullptr};
		if (low == high) return {new TreeNode(low)};
		for (int i = low; i <= high; ++i)
		{
			vector<TreeNode*> left  = generateSubTrees(low, i - 1);
			vector<TreeNode*> right = generateSubTrees(i + 1, high);
			for (auto l : left)
			{
				for (auto r : right)
				{
					TreeNode* root = new TreeNode(i);
					root->left     = l;
					root->right    = r;
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
	vector<TreeNode*> generateTrees(int n)
	{
		if (n < 1) return {};
		return generateSubTrees(1, n);
	}
};
