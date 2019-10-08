/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
		ostringstream os;
		serialize(root, os);
		return os.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		istringstream in(data);
		return deserialize(in);
	}

private:
	void serialize(TreeNode* root, ostringstream& encode)
	{
		if (!root)
			encode << "# ";
		else
		{
			encode << root->val << ' ';
			serialize(root->left, encode);
			serialize(root->right, encode);
		}
	}
	TreeNode* deserialize(istringstream& in)
	{
		string val;
		in >> val;
		if (val == "#") return nullptr;
		TreeNode* root = new TreeNode(atoi(val.c_str()));
		root->left     = deserialize(in);
		root->right    = deserialize(in);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
