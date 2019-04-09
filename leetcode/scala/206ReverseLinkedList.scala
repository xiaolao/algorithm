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

  def main(args String[]) {
  }

  def reverseList(head: ListNode): ListNode = {
    var pre: ListNode = null
    var cur: ListNode = head
    while(cur != null) {
      cur.next, pre, cur = pre, cur, cur.next
    }
    return pre
  }

  def Print(head: ListNode) String = {
    var s: String = ""
    var cur: ListNode = head
    while(cur != null) {
      s += cur.value
      cur = cur.next
    }
  }
}
