/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// Definition for singly-linked list.
// struct ListNode {
// 	int val;
// 	struct ListNode* next;
// };

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head)
	{
		struct ListNode* cur = head;
		while (head && head->val == val)
		{
			head = head->next;
			free(cur);
			cur = head;
		}
		struct ListNode* pre = cur;
		if (cur)
		{
			cur = cur->next;
		}
		while (cur)
		{
			if (cur->val == val)
			{
				pre->next = cur->next;
				free(cur);
				cur = pre->next;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
	}
	return head;
}
