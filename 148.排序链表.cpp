/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (65.58%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    64.4K
 * Total Submissions: 98.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *
 * 示例 1:
 *
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 *
 *
 * 示例 2:
 *
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* dummy = new ListNode(0);
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        return head ? mergeSort(head) : head;
    }
    ListNode* mergeSort(ListNode* head)
    {
        if (!head->next) return head;
        ListNode *slow = head, *fast = head, *pre;
        while (fast && fast->next)
        {
            pre  = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = nullptr;
        return merge(mergeSort(head), mergeSort(slow));
    }
    ListNode* merge(ListNode* l, ListNode* r)
    {
        if (!l) return r;
        if (!r) return l;
        ListNode* last = dummy;
        while (l && r)
        {
            if (l->val <= r->val)
            {
                last->next = l;
                l          = l->next;
            }
            else
            {
                last->next = r;
                r          = r->next;
            }
            last = last->next;
        }
        last->next = l ? l : r;
        return dummy->next;
    }
};
// @lc code=end
