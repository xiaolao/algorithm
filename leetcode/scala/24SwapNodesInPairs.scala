// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.


class ListNode(var _x: Int = 0) {
  var next: ListNode = null
  var x: Int = _x
}


object Solution {

  def main(args: Array[String]) {
    val node1: ListNode = new ListNode(1)
    val node2: ListNode = new ListNode(2)
    val node3: ListNode = new ListNode(3)
    val node4: ListNode = new ListNode(4)
    val node5: ListNode = new ListNode(5)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    assert(Print(node1) == "12345")
    val head = swapPairs(node1)
    assert(Print(head) == "21435")
  }

  def swapPairs(head: ListNode): ListNode = {

  }

  def Print(head: ListNode): String = {
    var s: String = ""
    var cur: ListNode = head
    while(cur != null) {
      s += cur.x.toString
      cur = cur.next
    }
    return s
  }
}
