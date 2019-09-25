/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
	int countNodes(TreeNode* root)
	{
		/*
		        if (!root) return 0;
		        int lheight = 0, rheight = 0;
		        TreeNode* pt = root;
		        while (pt)
		        {
		            ++lheight;
		            pt = pt->left;
		        }
		        pt = root;
		        while (pt)
		        {
		            ++rheight;
		            pt = pt->right;
		        }
		        if (lheight == rheight)
		            return (1 << lheight) - 1;
		        else
		            return 1 + countNodes(root->left) + countNodes(root->right);
		   */
		int res = 0;
		while (root)
		{
			int lmaxheight = 0, rmaxheight = 0;
			TreeNode* pt = root->left;
			while (pt)
			{
				++lmaxheight;
				pt = pt->left;
			}
			pt = root->right;
			while (pt)
			{
				++rmaxheight;
				pt = pt->left;
			}
			if (lmaxheight == rmaxheight)
			{
				res += (1 << lmaxheight);
				root = root->right;
			}
			else
			{
				res += (1 << rmaxheight);
				root = root->left;
			}
		}
		return res;
	}
};
