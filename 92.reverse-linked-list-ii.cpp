/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
	void reverseBetween(ListNode* head, ListNode* tail)
	{
		ListNode* cur = head->next;
		ListNode* pre = tail;
		ListNode* nex = cur->next;
		while (nex != tail)
		{
			cur->next = pre;
			pre       = cur;
			cur       = nex;
			nex       = cur->next;
		}
		cur->next  = pre;
		head->next = cur;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (m == n) return head;
		ListNode *pre, *nex = head;
		ListNode dummy(-1);
		dummy.next = head;

		pre = &dummy;
		for (int i = 1; i < m; ++i)
		{
			pre = pre->next;
		}
		for (int i = 0; i < n; ++i)
		{
			nex = nex->next;
		}
		reverseBetween(pre, nex);
		return dummy.next;
	}
};
