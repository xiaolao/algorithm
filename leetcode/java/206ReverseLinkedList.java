// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

// Follow up:
// A linked list can be reversed either iteratively or recursively. Could you implement both?
// Definition for singly-linked list.

// Definition for singly-linked list.
class ListNode {
    int value;
    ListNode next;

    public ListNode(int value) {
        this.value = value;
        this.next = null;
    }

    public String Print() {
        String s = "";
        ListNode node = this;
        while(node != null) {
            s += node.value;
            node = node.next;
        }
        return s;
    }
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
        assert(node1.Print() == "12345");
        Solution solution = new Solution();
        ListNode head = solution.reverseList(node1);
        assert(head.Print() == "54321");
    }

    public ListNode reverseList(ListNode head) {
        if (head == null) return head;

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

}
