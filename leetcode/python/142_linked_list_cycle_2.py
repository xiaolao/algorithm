# Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

# To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

# Note: Do not modify the linked list.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return
        slow, fast = head.next, head.next.next
        while fast is not None and fast.next is not None and slow is not fast:
            slow, fast = slow.next, fast.next.next
        if slow is not fast:
            return
        while slow is not head:
            slow, head = slow.next, head.next
        return slow


if __name__ == "__name__":
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    solution = Solution()
    assert solution.detectCycle(node1) is None
    node5.next = node2
    assert solution.detectCycle(node1) is node2
