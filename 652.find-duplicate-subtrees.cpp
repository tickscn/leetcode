/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
	{
		vector<TreeNode*> res;
		if (!root) return res;
		unordered_map<string, int> hashtab;
		recursion(root, hashtab, res);
		return res;
	}

private:
	string recursion(TreeNode* root, unordered_map<string, int>& tab, vector<TreeNode*>& res)
	{
		if (!root) return "N";
		string str = to_string(root->val) + " " + recursion(root->left, tab, res) + " " + recursion(root->right, tab, res);
		if (tab[str] == 1) res.push_back(root);
		++tab[str];
		return str;
	}
};
// @lc code=end
