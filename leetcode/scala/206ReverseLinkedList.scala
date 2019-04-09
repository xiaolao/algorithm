// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

// Follow up:
// A linked list can be reversed either iteratively or recursively. Could you implement both?
// Definition for singly-linked list.

// Definition for singly-linked list.

class ListNode(var _x: Int = 0) {
  var next: ListNode = null
  var x: Int = _x
}

object Solution {

  def main(args: Array[String]) {
    val node1 = new ListNode(1)
    val node2 = new ListNode(2)
    val node3 = new ListNode(3)
    val node4 = new ListNode(4)
    val node5 = new ListNode(5)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    assert(Print(node1) == "12345")
    val head = reverseList(node1)
    assert(Print(head) == "54321")
  }

  def reverseList(head: ListNode): ListNode = {
    var pre: ListNode = null
    var cur: ListNode = head
    while(cur != null) {
      val tmp = cur.next
      cur.next = pre
      pre = cur
      cur = tmp
    }
    return pre
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
