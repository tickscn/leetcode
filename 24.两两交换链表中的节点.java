/*
 * @lc app=leetcode.cn id=24 lang=java
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (65.30%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 149.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode pre = new ListNode(0);
        ListNode p1 = head;
        ListNode p2 = head.next;
        pre.next = head;
        head = p2;
        while (p1 != null && (p2 = p1.next) != null) {
            pre.next = p2;
            p1.next = p2.next;
            p2.next = p1;
            pre = p1;
            p1 = p1.next;
        }
        return head;
    }
}
// @lc code=end
