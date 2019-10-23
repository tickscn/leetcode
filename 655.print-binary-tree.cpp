/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
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
	vector<vector<string>> printTree(TreeNode* root)
	{
		int m = getHeight(root);
		int n = pow(2, m) - 1;
		vector<vector<string>> res(m, vector<string>(n, ""));
		recursion(root, 0, n - 1, 0, m, res);
		return res;
	}

private:
	int getHeight(TreeNode* root)
	{
		if (!root) return 0;
		return 1 + max(getHeight(root->left), getHeight(root->right));
	}
	void recursion(TreeNode* root, int beg, int end, int curH, int H, vector<vector<string>>& res)
	{
		if (!root || curH == H) return;
		res[curH][(beg + end) / 2] = to_string(root->val);
		recursion(root->left, beg, (beg + end) / 2, curH + 1, H, res);
		recursion(root->right, (beg + end) / 2 + 1, end, curH + 1, H, res);
	}
};
// @lc code=end
