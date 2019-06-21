/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val > l2->val)
			{
				p->next = l2;
				l2 = l2->next;
			}
			else
			{
				p->next = l1;
				l1 = l1->next;
			}
			p = p->next;
		}
		if (l1 == NULL)
		{
			p->next = l2;
		}
		else if (l2 == NULL)
		{
			p->next = l1;
		}
		return dummy->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		int n = lists.size();
		if (n == 0) return NULL;
		while (n > 1)
		{
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; i++) lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			n = k;
		}
		return lists[0];
	}
};
