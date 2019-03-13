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

/**
  *
  * @param key   键
  * @param value 值
  * @param prev  前驱节点指针
  * @param next  后继结点指针
  */
case class Node(
  key: Int, 
  value: Int, 
  var prev: Node = null,
  var next: Node = null
)

/**
  * 最近最少使用缓存类
  * @param _capacity 
  */
class LRUCache(_capacity: Int) {
  private var size: Int = 0
  private val head: Node = new Node(-1, -1)
  private val tail: Node = new Node(-1, -1)
  head.next = tail
  tail.prev = head
  private val items = collection.mutable.Map[Int, Node]()

  /**
    *
    * @param key 通过key获取value
    * @return value
    */
  def get(key: Int): Int = {
    items
      .get(key)
      .map{node => {
        remove(node)
        insert(node)
        node.value
      }
    }
    .getOrElse(-1)
  }

  /**
    *
    * @param key
    * @param value
    */
  def put(key: Int, value: Int) {
    val node = items.get(key) match {
      case Some(node) => 
        remove(node)
        node.copy(value=value)
      case None => 
        if (_capacity == size) {
          items -= tail.prev.key
          remove(tail.prev)
        } else {
          size += 1
        }
        Node(key, value)
    }
    insert(node)
    items += (key -> node)
  }

  /**
    * 删除双链表节点
    * @param node
    */
  def remove(node: Node) {
    node.prev.next = node.next
    node.next.prev = node.prev
  }

  /**
    * 只在双链表头部插入数据
    * @param node
    */
  def insert(node: Node) {
    head.next.prev = node
    node.next = head.next
    node.prev = head
    head.next = node
  }
}

object Solution {
  def main(args: Array[String]) {
    var cache = new LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    assert(cache.get(1) == 1)
    cache.put(3, 3)
    assert(cache.get(2) == -1)
    cache.put(4, 4)
    assert(cache.get(1) == -1)
    assert(cache.get(3) == 3)
    assert(cache.get(4) == 4)
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
