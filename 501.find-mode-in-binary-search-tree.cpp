/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
	vector<int> findMode(TreeNode* root)
	{
		vector<int> res;
		int maxCount = 1, tmpCount = 0;
		long preNum = LONG_MIN;
		if (!root) return res;
		stack<TreeNode*> St;
		while (root || !St.empty())
		{
			while (root)
			{
				St.push(root);
				root = root->left;
			}
			root = St.top();
			St.pop();
			if (root->val != preNum)
			{
				if (tmpCount > maxCount)
				{
					res.clear();
					res.push_back(preNum);
					maxCount = tmpCount;
				}
				else if (tmpCount == maxCount)
				{
					res.push_back(preNum);
				}
				tmpCount = 1;
				preNum   = root->val;
			}
			else
			{
				++tmpCount;
			}
			root = root->right;
		}
		if (tmpCount > maxCount)
		{
			res.clear();
			res.push_back(preNum);
		}
		else if (tmpCount == maxCount)
		{
			res.push_back(preNum);
		}
		return res;
	}
};
// @lc code=end
