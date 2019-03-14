# Reverse a singly linked list.

# Example:

# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL
# Follow up:

# A linked list can be reversed either iteratively or recursively. Could you implement both?

# Definition for singly-linked list.


class ListNode:
    """单链表节点"""

    def __init__(self, x):
        self.val = x
        self.next = None


class ListIterator:
    """链表迭代器"""

    def __init__(self, node: ListNode):
        self.current = node

    def __iter__(self):
        return self

    def __next__(self) -> int:
        if self.current is None:
            raise StopIteration
        result = self.current.val
        self.current = self.current.next
        return result


class LinkList:
    """单链表"""

    def __init__(self, val: int):
        self.head = self.tail = ListNode(val)

    def append(self, val: int):
        """添加节点到尾部"""
        node = ListNode(val)
        self.tail.next = node
        self.tail = node

    def __iter__(self) -> ListIterator:
        """返回列表迭代器对象"""
        return ListIterator(self.head)

    def __str__(self):
        return "".join(str(i) for i in self)


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, cur = None, head
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev


if __name__ == "__main__":
    link_list = LinkList(1)
    link_list.append(2)
    link_list.append(3)
    link_list.append(4)
    link_list.append(5)
    print(str(link_list))
