/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
private:
	ListNode* root;
	TreeNode* inorderListToBST(int l, int r)
	{
		if (l > r) return nullptr;
		int mid = (l + r) / 2;

		TreeNode* left = inorderListToBST(l, mid - 1);
		TreeNode* node = new TreeNode(root->val);

		node->left  = left;
		root        = root->next;
		node->right = inorderListToBST(mid + 1, r);
		return node;
	}

public:
	//	TreeNode* sortedListToBST(ListNode* head, ListNode* tail = nullptr)
	//	{
	//		if (head == tail) return nullptr;
	//		ListNode *slow = head, *fast = head->next;
	//		while (fast != tail && fast->next != tail)
	//		{
	//			slow = slow->next;
	//			fast = fast->next->next;
	//		}
	//		TreeNode* root = new TreeNode(slow->val);
	//		root->left     = sortedListToBST(head, slow);
	//		root->right    = sortedListToBST(slow->next, tail);
	//		return root;
	//	}
	TreeNode* sortedListToBST(ListNode* head)
	{
		root       = head;
		int length = 0;
		while (head)
		{
			++length;
			head = head->next;
		}
		return inorderListToBST(0, length - 1);
	}
};
