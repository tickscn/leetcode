/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/*
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};
*/
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int a = l1->val, b = l2->val, carry = 0;
		l1 = l1->next;
		l2 = l2->next;
		ListNode* head = new ListNode((a + b) % 10);
		ListNode* cur = head;
		carry = (a + b) / 10;
		while (l1 || l2)
		{
			if (l1)
			{
				a = l1->val;
				l1 = l1->next;
			}
			else
			{
				a = 0;
			}
			if (l2)
			{
				b = l2->val;
				l2 = l2->next;
			}
			else
			{
				b = 0;
			}
			cur->next = new ListNode((a + b + carry) % 10);
			cur = cur->next;
			carry = (a + b + carry) / 10;
		}
		if (carry) cur->next = new ListNode(1);
		return head;
	}
};
