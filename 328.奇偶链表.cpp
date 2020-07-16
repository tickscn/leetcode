/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *e1 = head, *b2 = head->next, *e2 = b2;
        while (e2 && e2->next)
        {
            ListNode* pt = e2->next;
            e2->next     = pt->next;
            e2           = e2->next;
            pt->next     = b2;
            e1->next     = pt;
            e1           = pt;
        }
        return head;
    }
};
// @lc code=end
