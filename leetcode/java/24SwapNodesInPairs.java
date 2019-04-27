// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

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
        assert toString(node1).equals("12345");
        ListNode head = swapPairs(node1);
        assert toString(head).equals("21435");
    }

    public static ListNode swapPairs(ListNode head) {
        ListNode sentinel = new ListNode(0);
        ListNode prev = sentinel;
        prev.next = head;
        while (prev.next != null && prev.next.next != null) {
            ListNode a = prev.next;
            ListNode b = a.next;
            ListNode c = b.next;
            prev.next = b;
            b.next = a;
            a.next = c;
            prev = a;
        }
        return sentinel.next;
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
