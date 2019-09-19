/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		if (!root) return {};
		vector<vector<int>> res;
		vector<int> path;
		preorderPath(root, sum, 0, path, res);
		return res;
	}
	void preorderPath(TreeNode* root, int sum, int curSum, vector<int>& path, vector<vector<int>>& res)
	{
		if (!root) return;
		curSum += root->val;
		path.push_back(root->val);
		if (!root->left && !root->right)
		{
			if (curSum == sum)
			{
				res.push_back(path);
			}
			path.pop_back();
			curSum -= root->val;
		}
		else
		{
			preorderPath(root->left, sum, curSum, path, res);
			preorderPath(root->right, sum, curSum, path, res);
			path.pop_back();
			curSum -= root->val;
		}
	}
};
