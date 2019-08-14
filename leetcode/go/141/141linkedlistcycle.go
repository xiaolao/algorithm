// Given a linked list, determine if it has a cycle in it.

// To represent a cycle in the given linked list, we use an integer
// pos which represents the position (0-indexed) in the linked list
// where tail connects to. If pos is -1, then there is no cycle in the linked list.

package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if fast == slow {
			return true
		}
	}
	return false
}
