/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator
{
private:
	vector<int> iter;
	int now;

public:
	BSTIterator(TreeNode* root) : now(0) { Init(root); }
	void Init(TreeNode* root)
	{
		if (root)
		{
			Init(root->left);
			iter.push_back(root->val);
			Init(root->right);
		}
	}
	/** @return the next smallest number */
	int next() { return iter[now++]; }

	/** @return whether we have a next smallest number */
	bool hasNext() { return now < iter.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
