/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> St;
		TreeNode* pre = nullptr;
		while (root || !St.empty())
		{
			while (root)
			{
				St.push(root);
				root = root->left;
			}
			while (!St.empty())
			{
				root = St.top();
				if (root->right && root->right != pre)
				{
					root = root->right;
					break;
				}
				else
				{
					St.pop();
					res.push_back(root->val);
					pre  = root;
					root = nullptr;
				}
			}
		}
		return res;
	}
};
