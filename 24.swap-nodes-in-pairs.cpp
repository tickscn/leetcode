/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
	ListNode* swapPairs(ListNode* head)
	{
		ListNode *pre = nullptr, *p1 = head, *p2;
		while (p1 && p1->next)
		{
			p2 = p1->next;
			if (!pre)
			{
				p1->next = p2->next;
				p2->next = p1;
				head = p2;
				pre = p1;
			}
			else
			{
				pre->next = p2;
				p1->next = p2->next;
				p2->next = p1;
				pre = p1;
			}
			p1 = pre->next;
		}
		return head;
	}
};
