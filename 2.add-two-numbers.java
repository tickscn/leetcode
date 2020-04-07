/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.86%)
 * Likes:    7454
 * Dislikes: 1930
 * Total Accepted:    1.3M
 * Total Submissions: 3.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int a = l1.val;
        int b = l2.val;
        int carry = 0;
        ListNode ret = new ListNode((a + b) % 10);
        carry = (a + b) / 10;
        ListNode cur = ret;
        l1 = l1.next;
        l2 = l2.next;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                a = l1.val;
                l1 = l1.next;
            } else {
                a = 0;
            }
            if (l2 != null) {
                b = l2.val;
                l2 = l2.next;
            } else {
                b = 0;
            }
            cur.next = new ListNode((a + b + carry) % 10);
            cur = cur.next;
            carry = (a + b + carry) / 10;
        }
        if (carry == 1)
            cur.next = new ListNode(1);
        return ret;

    }
}
// @lc code=end
