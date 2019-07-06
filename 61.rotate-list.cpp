/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head)
		{
			if (k == 0) return head;
			int length    = 0;
			ListNode* pre = head;
			while (pre)
			{
				pre = pre->next;
				++length;
			}
			k %= length;
			if (k == 0) return head;
			pre            = head;
			ListNode* tail = head;
			for (int i = 0; i < k; ++i)
			{
				tail = tail->next;
			}
			while (tail->next)
			{
				pre  = pre->next;
				tail = tail->next;
			}
			tail->next = head;
			head       = pre->next;
			pre->next  = nullptr;
		}
		return head;
	}
};
