// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Definition for singly-linked list.
package leetcode

func swapPairs(head *ListNode) *ListNode {
	sentinel := &ListNode{0, nil}
	prev, prev.Next = sentinel, head
	for prev != nil && prev.Next != nil {
		a := prev.Next
		b := a.Next
		prev.Next, b.Next, a.Next = b, a, b.Next
		prev = a
	}
	return sentinel.Next
}
