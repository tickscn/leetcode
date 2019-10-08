/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string res;
		serialize(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		istringstream in(data);
		int val;
		TreeNode* root = nullptr;
		while (in >> val)
		{
			TreeNode* node = new TreeNode(val);
			root           = insertNode(root, node);
		}
		return root;
	}

private:
	void serialize(TreeNode* root, string& res)
	{
		if (root)
		{
			res += to_string(root->val) + ' ';
			serialize(root->left, res);
			serialize(root->right, res);
		}
	}
	TreeNode* insertNode(TreeNode* root, TreeNode* node)
	{
		TreeNode* pre = nullptr;
		TreeNode* cur = root;
		while (cur)
		{
			pre = cur;
			if (node->val < cur->val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (!pre) return node;
		if (node->val < pre->val)
			pre->left = node;
		else
			pre->right = node;
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
