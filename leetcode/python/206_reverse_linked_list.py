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


if __name__ == "__main__":
    head = ListNode(1)
    cur = head
    for val in range(2, 6):
        node = ListNode(val)
        cur.next = node
        cur = node
    solution = Solution()
    head = solution.reverseList(head)
    cur = head
    while cur:
        print(f"{cur.val} \n")
        cur = cur.next
