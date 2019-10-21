/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
	vector<double> averageOfLevels(TreeNode* root)
	{
		vector<double> res;
		queue<TreeNode*> Qe;
		Qe.push(root);
		while (!Qe.empty())
		{
			double ave = 0.0;
			int size   = Qe.size();
			for (int i = size; i > 0; --i)
			{
				root = Qe.front();
				Qe.pop();
				ave += root->val;
				if (root->left) Qe.push(root->left);
				if (root->right) Qe.push(root->right);
			}
			res.push_back(ave / size);
		}
		return res;
	}
};
// @lc code=end
