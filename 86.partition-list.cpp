/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
	ListNode* partition(ListNode* head, int x)
	{
		if (!head || !head->next) return head;
		ListNode dummy(-1);
		dummy.next     = head;
		ListNode* last = &dummy;
		while (last->next && last->next->val < x) last = last->next;
		ListNode* pre = last;
		ListNode* cur = pre->next;

		while (cur)
		{
			if (cur->val < x)
			{
				pre->next  = cur->next;
				cur->next  = last->next;
				last->next = cur;
				last       = cur;
				cur        = pre->next;
			}
			else
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return dummy.next;
	}
};
