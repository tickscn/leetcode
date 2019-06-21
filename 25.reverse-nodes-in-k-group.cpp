/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
	ListNode* reverseKLists(ListNode* pre, ListNode* next)
	{
		ListNode *last = pre->next, *cur = last->next;
		while (cur != next)
		{
			last->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = last->next;
		}
		return last;
	}
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (!head || k == 1) return head;
		ListNode dummy(-1), *pre = &dummy, *cur = head;
		dummy.next = head;
		for (int i = 1; cur; ++i)
		{
			if (i % k == 0)
			{
				pre = reverseKLists(pre, cur->next);
				cur = pre->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return dummy.next;
	}
};
