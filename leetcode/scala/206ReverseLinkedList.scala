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
    val head: ListNode = new ListNode(1)
    val node2: ListNode = new ListNode(2)
    val node3: ListNode = new ListNode(3)
    val node4: ListNode = new ListNode(4)
    val node5: ListNode = new ListNode(5)
    head.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    assert(toString(head) == "12345")
    val tail: ListNode = reverseList(head)
    assert(toString(tail) == "54321")
  }

  def reverseList(head: ListNode): ListNode = {
    if (head == null || head.next == null) return head

    def reverse(node: ListNode, nodeNext: ListNode): ListNode = {
      if (nodeNext == null) return node

      val nodeNextNext = nodeNext.next
      nodeNext.next = node
      reverse(nodeNext, nodeNextNext)
    }
    reverse(null, head)
  }

  def toString(head: ListNode): String = {
    var node: ListNode = head
    var s: String = ""
    while (node != null) {
      s = s + node.x.toString()
      node = node.next
    }
    return s
>>>>>>> 1bae8b8c15b5cce9940ed48e1469f85a46832186
  }
}
