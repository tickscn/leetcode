/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */
/*
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};
*/
#include <queue>
using namespace std;

class Solution
{
public:
	vector<vector<int>> levelOrder(Node* root)
	{
		vector<vector<int>> res;
		if (!root) return res;
		queue<Node*> Nque;
		Nque.push(root);
		while (!Nque.empty())
		{
			queue<Node*> nextQueue;
			vector<int> values;
			while (!Nque.empty())
			{
				Node* current = Nque.front();
				Nque.pop();
				values.push_back(current->val);
				for (Node* node : current->children)
				{
					nextQueue.push(node);
				}
			}
			res.push_back(values);
			Nque = nextQueue;
		}
		return res;
	}
};
