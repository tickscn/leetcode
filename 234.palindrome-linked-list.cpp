/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
	bool isPalindrome(ListNode* head)
	{
		if (head)
		{
			ListNode* h = head;
			ListNode* m = midOfList(head);
			m = reverseList(m);
			while (m)
			{
				if (h->val != m->val)
					return false;
				h = h->next;
				m = m->next;
			}
		}
		return true;
	}
	ListNode* midOfList(ListNode* head)
	{
		ListNode *tail = head, *mid = head;
		while (tail && tail->next)
		{
			mid = mid->next;
			tail = tail->next->next;
		}
		if (tail)
			mid = mid->next;
		return mid;
	}
	ListNode* reverseList(ListNode* head)
	{
		if (head && head->next)
		{
			ListNode* next;
			ListNode* cur = head;
			ListNode* pre = nullptr;
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
};
