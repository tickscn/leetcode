/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode* next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	struct ListNode* ret = l1;
	struct ListNode* pl1 = l1;
	struct ListNode* pl2 = l2;
	if (l1->val > l2->val)
	{
		l2 = l2->next;
		pl2->next = l1;
		ret = pl1 = pl2;
		pl2 = l2;
	}
	else
	{
		l1 = l1->next;
	}

	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			l2 = l2->next;
			pl1->next = pl2;
			pl1 = pl2;
			pl2->next = l1;
			pl2 = l2;
		}
		else
		{
			pl1 = l1;
			l1 = l1->next;
		}
	}
	if (!l1)
		pl1->next = l2;
	return ret;
}
