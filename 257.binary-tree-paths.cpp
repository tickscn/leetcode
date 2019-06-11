/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <deque>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> vs(0);
		int i = -1;
		if (!root)
			return vs;
		deque<TreeNode*> tdq;
		TreeNode *pre = nullptr, *cur = nullptr;
		tdq.push_back(root);
		while (!tdq.empty())
		{
			cur = tdq.back();
			if (!pre || pre->left == cur || pre->right == cur)
			{
				if (cur->left)
					tdq.push_back(cur->left);
				else if (cur->right)
					tdq.push_back(cur->right);
			}
			else if (pre == cur->left)
			{
				if (cur->right)
					tdq.push_back(cur->right);
			}
			else
			{
				if (!cur->left && !cur->right)
				{
					deque<TreeNode*> tmp = tdq;
					pre = tmp.front();
					tmp.pop_front();
					vs.push_back(to_string(pre->val));
					++i;
					while (!tmp.empty())
					{
						pre = tmp.front();
						tmp.pop_front();
						vs[i] += "->" + to_string(pre->val);
					}
				}
				tdq.pop_back();
			}
			pre = cur;
		}
		return vs;
	}
};
