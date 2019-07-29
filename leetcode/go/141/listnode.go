package leetcode

import "strconv"

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewListNode(val int) *ListNode {
	return &ListNode{val, nil}
}

func PrintLinkedList(head *ListNode) string {
	var s string
	cur := head
	for cur != nil {
		s += strconv.Itoa(cur.Val)
		cur = cur.Next
	}
	return s
}
