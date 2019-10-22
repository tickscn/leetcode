/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
	bool findTarget(TreeNode* root, int k)
	{
		unordered_set<int> set;
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
			if (set.count(k - root->val)) return true;
			set.insert(root->val);
			root = root->right;
		}
		return false;
	}
};
// @lc code=end
