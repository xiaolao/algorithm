class Node:
    """双链表节点"""

    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None


class LRUCache:
    """最近最少使用。使用字典来保存key-value信息，
    保证get的时间复杂度为o(1)。使用双链表来保存最
    近最少使用"""

    def __init__(self, capacity: int):
        """
        :type capacity: int
        """
        self.items = {}
        self.capacity = capacity
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        """
        :type key: int
        :rtype: int
        """
        if key in self.items:
            node = self.items[key]
            self._remove(node)
            self._insert(node)
            return node.value
        return -1

    def put(self, key: int, value: int):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.items:
            node = self.items[key]
            self._remove(node)
            node.value = value
            self._insert(node)
        else:
            if len(self.items) == self.capacity:
                node = self.tail.prev
                del self.items[node.key]
                self._remove(node)
            node = Node(key, value)
            self._insert(node)
            self.items[key] = node

    def _remove(self, node: Node):
        n = node.next
        p = node.prev
        n.prev = p
        p.next = n
        node.next = None
        node.prev = None

    def _insert(self, node: Node):
        """将节点插入"""
        n = self.head.next
        self.head.next = node
        node.prev = self.head
        n.prev = node
        node.next = n


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

if __name__ == "__main__":
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    assert cache.get(1) == 1
    cache.put(3, 3)
    assert cache.get(2) == -1
    cache.put(4, 4)
    assert cache.get(1) == -1
    assert cache.get(3) == 3
    assert cache.get(4) == 4
