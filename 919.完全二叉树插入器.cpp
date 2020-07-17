/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
    vector<TreeNode*> data;

public:
    CBTInserter(TreeNode* root)
    {
        if (root)
        {
            queue<TreeNode*> Q;
            Q.push(root);
            while (!Q.empty())
            {
                for (int i = Q.size(); i > 0; --i)
                {
                    TreeNode* pt = Q.front();
                    data.push_back(pt);
                    Q.pop();
                    if (pt->left) Q.push(pt->left);
                    if (pt->right) Q.push(pt->right);
                }
            }
        }
    }

    int insert(int v)
    {
        TreeNode* Node = new TreeNode(v);
        TreeNode* pt   = data[(data.size() - 1) / 2];
        data.push_back(Node);
        if (pt->left)
            pt->right = Node;
        else
            pt->left = Node;
        return pt->val;
    }

    TreeNode* get_root()
    {
        return data[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
