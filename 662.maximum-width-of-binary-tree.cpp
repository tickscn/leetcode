/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
	int widthOfBinaryTree(TreeNode* root)
	{
		int res = 0;
		if (root)
		{
			queue<pair<TreeNode*, size_t>> Qe;
			Qe.push({root, 1});
			while (!Qe.empty())
			{
				size_t left = Qe.front().second;
				size_t right;
				for (size_t i = Qe.size(); i > 0; --i)
				{
					TreeNode* pt = Qe.front().first;
					right        = Qe.front().second;
					Qe.pop();
					if (pt->left) Qe.push({pt->left, 2 * right});
					if (pt->right) Qe.push({pt->right, 2 * right + 1});
				}
				res = max(res, (int)(right - left + 1));
			}
		}
		return res;
	}
};
// @lc code=end
