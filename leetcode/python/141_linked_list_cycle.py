# Given a linked list, determine if it has a cycle in it.

# To represent a cycle in the given linked list, we use an integer
# pos which represents the position (0-indexed) in the linked list
# where tail connects to. If pos is -1, then there is no cycle in the linked list.


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        slow, fast = head, head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False


if __name__ == "__main__":
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    node5.next = node2
    solution = Solution()
    assert solution.hasCycle(node1) is True
    node5.next = None
    assert solution.hasCycle(node1) is False

