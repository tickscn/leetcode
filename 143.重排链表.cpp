/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 46.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * 示例 1:
 *
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 *
 * 示例 2:
 *
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 *
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
    void reorderList(ListNode* head)
    {
        if (head && head->next && head->next->next)
        {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            fast             = slow->next->next;
            slow->next->next = nullptr;
            while (fast)
            {
                ListNode* cur = fast;
                fast          = fast->next;
                cur->next     = slow->next;
                slow->next    = cur;
            }
            fast       = slow->next;
            slow->next = nullptr;
            while (fast)
            {
                ListNode* cur = fast;
                fast          = fast->next;
                cur->next     = head->next;
                head->next    = cur;
                head          = cur->next;
            }
        }
    }
};
// @lc code=end
