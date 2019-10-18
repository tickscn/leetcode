/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
	vector<int> largestValues(TreeNode* root)
	{
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> Qe;
		Qe.push(root);
		while (!Qe.empty())
		{
			int max = INT_MIN;
			for (int i = Qe.size(); i > 0; --i)
			{
				root = Qe.front();
				Qe.pop();
				if (root->val > max) max = root->val;
				if (root->left) Qe.push(root->left);
				if (root->right) Qe.push(root->right);
			}
			res.push_back(max);
		}
		return res;
	}
};
// @lc code=end
