/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *point = head, *res = head, *pre = nullptr;
		while (n > 0)
		{
			point = point->next;
			--n;
		}
		while (point)
		{
			point = point->next;
			pre = res;
			res = res->next;
		}
		if (!pre)
		{
			head = head->next;
			delete res;
		}
		else
		{
			pre->next = res->next;
			delete res;
		}

		return head;
	}
};
