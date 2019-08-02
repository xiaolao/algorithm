// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.
package main

func reverseKGroup(head *ListNode, k int) *ListNode {
	cur, count := head, 0
	for cur != nil && count < k {
		cur = cur.Next
		count++
	}
	if count < k {
		return head
	}
	cur = reverseKGroup(cur, k)
	for count > 0 {
		head.Next, head, cur = cur, head.Next, head
		count--
	}
	return cur
}
