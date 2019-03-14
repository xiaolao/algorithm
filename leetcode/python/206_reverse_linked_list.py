# Reverse a singly linked list.

# Example:

# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL
# Follow up:

# A linked list can be reversed either iteratively or recursively. Could you implement both?

# Definition for singly-linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, cur = None, head
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev


if __name__ == "__main__":
    def l2s(cur: ListNode) -> str:
        vs = ""
        while cur is not None:
            vs += str(cur.val)
            cur = cur.next
        return vs
    head = node1 = ListNode(1)
    node1.next = node2 = ListNode(2)
    node2.next = node3 = ListNode(3)
    node3.next = node4 = ListNode(4)
    node4.next = node5 = ListNode(5)
    old = l2s(head)
    solution = Solution()
    head = solution.reverseList(head)
    new = l2s(head)
    assert old == new[::-1]
