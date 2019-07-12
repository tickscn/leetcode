/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */
/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
*/
class Solution
{
public:
	void deleteListnode(ListNode* beg, ListNode* end)
	{
		ListNode* pt = beg->next;
		ListNode* pd;
		beg->next = end;
		while (pt != end)
		{
			pd = pt;
			pt = pt->next;
			delete pd;
		}
	}
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head || !head->next) return head;
		ListNode dummy(-1);
		dummy.next    = head;
		ListNode *beg = &dummy, *end = head->next;
		while (end)
		{
			while (end && end->val == beg->next->val)
			{
				end = end->next;
			}
			if (end != beg->next->next)
				deleteListnode(beg, end);
			else if (end)
			{
				beg = beg->next;
				end = end->next;
			}
		}
		return dummy.next;
	}
};
