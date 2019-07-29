// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Definition for singly-linked list.
package leetcode

func swapPairs(head *ListNode) *ListNode {
	sentinal := &ListNode{Val: 0, Next: head}
	pre := sentinal
	for pre.Next != nil && pre.Next.Next != nil {
		a := pre.Next
		b := a.Next
		pre.Next, b.Next, a.Next = b, a, b.Next
		pre = a
	}
	return sentinal.Next
}
