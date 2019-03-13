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
  var prev: Node,
  var next: Node
)

/**
  *
  * @param _capacity
  */
class LRUCache(_capacity: Int) {

  /**
    * 最近最少使用缓存类
    * @param key 通过key获取value
    * @return value
    */
  def get(key: Int): Int = {

  }

  /**
    *
    * @param key
    * @param value
    */
  def put(key: Int, value: Int) {

  }

  /**
    *
    * @param node
    */
  def remove(node: Node) {
  }

  /**
    *
    * @param node
    */
  def insert(node: Node) {
  }
}

object Solution {
  def main(args: Array[String]) {
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
