package leetcode

import "testing"

func TestHasCycle(t *testing.T) {
	node1 := NewListNode(1)
	node2 := NewListNode(2)
	node3 := NewListNode(3)
	node4 := NewListNode(4)
	node5 := NewListNode(5)
	node1.Next = node2
	node2.Next = node3
	node3.Next = node4
	node4.Next = node5
	node5.Next = node2
	if !hasCycle(node1) {
		t.Error("141 hasCycle doesn't work correctly!")
	}
	node5.Next = nil
	if hasCycle(node1) {
		t.Error("141 hasCycle doesn't work correctly!")
	}
}
