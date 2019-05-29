/*
 * @lc app=leetcode id=141 lang=c
 *
 * [141] Linked List Cycle
 */

// Definition for singly-linked list.
// #include <stdbool.h>
// struct ListNode {
// 	int val;
// 	struct ListNode* next;
// };

bool hasCycle(struct ListNode* head)
{
	if (!head || !head->next)
		return false;
	struct ListNode *slow = head, *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}
