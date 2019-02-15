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

// 解题思路：

package leetcode

type Node struct {
	key   int
	value int
	next  *Node
	prev  *Node
}

func newNode(key int, value int) *Node {
	return &Node{
		key:   key,
		value: value,
		next:  nil,
		prev:  nil,
	}
}

type LRUCache struct {
	capacity int
	head     *Node
	tail     *Node
	items    map[int]*Node
}

func Constructor(capacity int) LRUCache {
	if capacity <= 0 {
		panic("capacity must be positive value")
	}
	head := newNode(0, 0)
	tail := newNode(0, 0)
	head.next = tail
	tail.prev = head
	return LRUCache{
		capacity: capacity,
		items:    make(map[int]*Node),
		head:     head,
		tail:     tail,
	}
}

// 使用map保存key-value信息，使得get操作时间复杂度为o(1)
func (this *LRUCache) Get(key int) int {
	if node, ok := this.items[key]; ok {
		this.remove(node)
		this.insert(node)
		return node.value
	}
	return -1
}

// 使用双链表来保存最近最少使用信息，head.next为最新数据
// tail.prev为最旧的数据，
func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.items[key]; ok {
		node.value = value
		this.remove(node)
		this.insert(node)
	} else {
		if len(this.items) == this.capacity {
			node = this.tail.prev
			delete(this.items, node.key)
			this.remove(node)
		}
		node = newNode(key, value)
		this.insert(node)
		this.items[key] = node
	}
}

// 删除特定节点
func (this *LRUCache) remove(node *Node) {
	n := node.next
	p := node.prev
	n.prev = p
	p.next = n
	node.prev = nil
	node.next = nil
}

// 只从双链表头部插入节点
func (this *LRUCache) insert(node *Node) {
	n := this.head.next
	node.prev = this.head
	this.head.next = node
	node.next = n
	n.prev = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
