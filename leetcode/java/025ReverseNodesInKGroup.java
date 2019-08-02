// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

import java.lang.String;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {

    public static void main(String[] args) throws Exception {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        ListNode head = reverseKGroup(node1, 3);
        assert(toString(head).equals("32145")): "025 reverseKGroup not work correctly.";
    }

    /**
     * head: the head node of a linked list.
     * k: group number that need to be reverse.
     */
    public static ListNode reverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode cur = head;
        while (cur != null && count < k) {
            cur = cur.next;
            count++;
        }
        if (count < k) return head;
        cur = reverseKGroup(cur, k);
        while (count > 0) {
            ListNode tmp = head.next;
            head.next = cur;
            cur = head;
            head = tmp;
            count--;
        }
        return cur;
    }

    public static String toString(ListNode head) {
        String s = "";
        ListNode node = head;
        while (node != null) {
            s = s + String.valueOf(node.val);
            node = node.next;
        }
        return s;
    }
}
