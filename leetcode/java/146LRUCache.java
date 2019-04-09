// 题目:
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

import java.util.Hashtable;


class LRUCache {

    class DLinkedNode {
        int key, value;
        DLinkedNode prev;
        DLinkedNode next;
    }

    // count为当前缓存数，capacity为缓存容量
    private int count, capacity;
    // head,tail为哨兵节点
    private DLinkedNode head, tail;
    // hash表用于在o(1)的时间内快速的获取存储数据
    private Hashtable<Integer, DLinkedNode> items = new Hashtable<Integer, DLinkedNode>();

    // 测试
    public static void main(String[] args) {
        LRUCache cache = new LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        assert(cache.get(1) == 1);
        cache.put(3, 3);
        assert(cache.get(2) == -1);
        cache.put(4, 4);
        assert(cache.get(1) == -1);
        assert(cache.get(3) == 3);
        assert(cache.get(4) == 4);
    }

    // 初始化LRUCache对象, 对象构造器
    public LRUCache(int capacity) {
        this.count = 0;
        this.capacity = capacity;
        this.head = new DLinkedNode();
        this.tail = new DLinkedNode();
        this.head.prev = null;
        this.tail.next = null;
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    // 获取缓存值
    public int get(int key) {
        DLinkedNode node = this.items.get(key);
        if (node == null) {
            return -1;
        }
        this.remove(node);
        this.insert(node);
        return node.value;
    }

    // 放置缓存值
    public void put(int key, int value) {
        DLinkedNode node = this.items.get(key);
        if (node == null) {
            node = new DLinkedNode();
            node.key = key;
            node.value = value;
            this.items.put(key, node);
            this.insert(node);
            ++this.count;
            if (this.count > this.capacity) {
                this.items.remove(this.tail.prev.key);
                this.remove(this.tail.prev);
                --this.count;
            }
        } else {
            // 更新节点的值
            node.value = value;
            this.remove(node);
            this.insert(node);
        }
    }

    // 移除节点
    private void remove(DLinkedNode node) {
        DLinkedNode prev = node.prev;
        DLinkedNode next = node.next;
        prev.next = next;
        next.prev = prev;
    }

    // 插入新节点到头结点后
    private void insert(DLinkedNode node) {
        node.prev = this.head;
        node.next = this.head.next;
        this.head.next.prev = node;
        this.head.next = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
