/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		ListNode* pt = node->next;
		node->val = pt->val;
		node->next = pt->next;
		delete pt;
	}
};
