// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Definition for singly-linked list.
package leetcode

import "testing"

func TestSwapPairs(t *testing.T) {
	node1 := NewListNode(1)
	node2 := NewListNode(2)
	node3 := NewListNode(3)
	node4 := NewListNode(4)
	node5 := NewListNode(5)
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	head := swapPairs(node1)
	if PrintLinkedList(head) != "21435" {
		t.Error("24 swapPairs doesn't work correctly!")
	}
}
