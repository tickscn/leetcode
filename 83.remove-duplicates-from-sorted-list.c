/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */
// Definition for singly-linked list.
// struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* p = head;
	struct ListNode* q;
	while (p)
	{
		q = p->next;
		if (q && p->val == q->val)
		{
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
	return head;
}
