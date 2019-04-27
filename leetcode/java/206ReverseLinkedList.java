// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

// Follow up:
// A linked list can be reversed either iteratively or recursively. Could you implement both?

import java.lang.String;


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {val = x;}
}


class Solution {
    
    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        assert(toString(node1).equals("12345"));
        ListNode tail = reverseList(node1);
        assert(toString(tail).equals("54321"));
    }


    public static ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
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
