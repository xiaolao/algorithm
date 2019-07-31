##Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

#k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

#Example:

#Given this linked list: 1->2->3->4->5

#For k = 2, you should return: 2->1->4->3->5

#For k = 3, you should return: 3->2->1->4->5

#Note:

#Only constant extra memory is allowed.
#You may not alter the values in the list's nodes, only nodes itself may be changed. Definition for singly-linked list.


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cur, count = head, 0
        while cur and count < k:
            cur = cur.next
            count += 1
            if not cur:
                break
            cur = self.reverseKGroup(cur, k)
            while count > 0:


def println(head: ListNode) -> str:
    s = ""
    while head:
        s += str(head.val)
        head = head.next
    return s


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
    solution = Solution()
    assert println(solution.reverseKGroup(node1, 3)) == "21435"
