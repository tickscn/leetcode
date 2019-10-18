/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
	TreeNode* convertBST(TreeNode* root)
	{
		if (root)
		{
			int pre = 0;
			stack<TreeNode*> St;
			TreeNode* pt = root;
			while (pt || !St.empty())
			{
				while (pt)
				{
					St.push(pt);
					pt = pt->right;
				}
				pt = St.top();
				St.pop();
				pt->val += pre;
				pre = pt->val;
				pt  = pt->left;
			}
		}
		return root;
	}
};
// @lc code=end
