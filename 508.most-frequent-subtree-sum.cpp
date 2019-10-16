/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
	vector<int> findFrequentTreeSum(TreeNode* root)
	{
		vector<int> res;
		if (root)
		{
			unordered_map<int, int> hashMap;
			dfs(root, hashMap, res);
		}
		return res;
	}

private:
	int cnt = 1;
	int dfs(TreeNode* root, unordered_map<int, int>& hashMap, vector<int>& res)
	{
		if (!root) return 0;
		int left  = dfs(root->left, hashMap, res);
		int right = dfs(root->right, hashMap, res);
		int sum   = left + right + root->val;
		++hashMap[sum];
		if (hashMap[sum] > cnt)
		{
			res.clear();
			res.push_back(sum);
			cnt = hashMap[sum];
		}
		else if (hashMap[sum] == cnt)
		{
			res.push_back(sum);
		}
		return sum;
	}
};
// @lc code=end
