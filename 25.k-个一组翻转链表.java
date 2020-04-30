import com.sun.org.apache.xpath.internal.operations.Neg;

/*
 * @lc app=leetcode.cn id=25 lang=java
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (58.28%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 91K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public static ListNode reverseKLists(ListNode beg, ListNode end) {
        ListNode last = beg.next;
        ListNode next = last.next;
        while (next != end) {
            last.next = next.next;
            next.next = beg.next;
            beg.next = next;
            next = last.next;
        }
        return last;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        ListNode beg = dummy;
        ListNode end = head;
        beg.next = end;
        for (int i = 1;; i++) {
            if (i % (k + 1) == 0)
                beg = reverseKLists(beg, end);
            else {
                if (end != null)
                    end = end.next;
                else
                    break;
            }
        }
        return dummy.next;
    }
}
// @lc code=end
