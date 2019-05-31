/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
	if (head && head->next)
	{
		struct ListNode* next;
		struct ListNode* cur = head;
		struct ListNode* pre = NULL;
		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		head = pre;
	}
	return head;
}
