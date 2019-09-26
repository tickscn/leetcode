/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
	int rob(TreeNode* root)
	{
		/****************************************************************************
		 * time limit exceeded
		    if (!root) return 0;
		    int val = 0;
		    if (root->left) val += rob(root->left->left) + rob(root->left->right);
		    if (root->right) val += rob(root->right->left) + rob(root->right->right);
		    return max(val + root->val, rob(root->left) + rob(root->right));
		***************************************************************************/
		/*******************************************************************
		 * 不是隔行抢
		    if (!root) return 0;
		    int dp[2] = {0, 0};
		    int k     = 0;
		    queue<TreeNode*> Qe;
		    Qe.push(root);
		    while (!Qe.empty())
		    {
		        int val = 0;
		        for (int i = Qe.size(); i > 0; --i)
		        {
		            TreeNode* pt = Qe.front();
		            Qe.pop();
		            val += pt->val;
		            if (pt->left) Qe.push(pt->left);
		            if (pt->right) Qe.push(pt->right);
		        }
		        dp[k % 2] = max(dp[k % 2] + val, dp[(k + 1) % 2]);
		        ++k;
		    }
		    return dp[(k + 1) % 2];
		***********************************************************************/
		int l = 0, r = 0;
		return dfsHelper(root, l, r);
	}
	int dfsHelper(TreeNode* root, int& l, int& r)
	{
		if (!root) return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = dfsHelper(root->left, ll, lr);
		r = dfsHelper(root->right, rl, rr);
		return max(root->val + ll + lr + rr + rl, l + r);
	}
};
