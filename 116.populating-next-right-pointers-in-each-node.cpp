/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution
{
public:
	Node* connect(Node* root)
	{
		if (!root) return root;
		Node* preLevelBegin = root;
		Node dummy(0, nullptr, nullptr, nullptr);
		Node* levelView;
		do
		{
			levelView = &dummy;
			for (auto par = preLevelBegin; par; par = par->next)
			{
				if (par->left)
				{
					levelView->next = par->left;
					levelView       = par->left;
					if (par->right)
					{
						levelView->next = par->right;
						levelView       = par->right;
					}
				}
				else
					return root;
			}
			preLevelBegin = dummy.next;
		} while (preLevelBegin->left);

		return root;
	}
};
