/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
	int diameterOfBinaryTree(TreeNode* root)
	{
		if (!root) return 0;
		int res = getHeight(root->left) + getHeight(root->right);
		return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
	}

private:
	unordered_map<TreeNode*, int> height;
	int getHeight(TreeNode* node)
	{
		if (!node) return 0;
		if (height.count(node)) return height[node];
		int h               = 1 + max(getHeight(node->left), getHeight(node->right));
		return height[node] = h;
	}
};
// @lc code=end
