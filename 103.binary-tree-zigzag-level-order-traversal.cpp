/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		if (!root) return {};
		stack<TreeNode*>* st1 = new stack<TreeNode*>;
		stack<TreeNode*>* st2 = new stack<TreeNode*>;
		vector<vector<int>> res;
		st1->push(root);
		bool right = true;
		while (!st1->empty())
		{
			vector<int> level;
			for (int i = st1->size(); i > 0; --i)
			{
				TreeNode* pt = st1->top();
				st1->pop();
				level.push_back(pt->val);
				if (right)
				{
					if (pt->left) st2->push(pt->left);
					if (pt->right) st2->push(pt->right);
				}
				else
				{
					if (pt->right) st2->push(pt->right);
					if (pt->left) st2->push(pt->left);
				}
			}
			right = !right;
			res.push_back(level);
			swap(st1, st2);
		}
		delete st1;
		delete st2;
		return res;
	}
};
