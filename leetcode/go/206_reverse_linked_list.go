// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

// Follow up:
// A linked list can be reversed either iteratively or recursively. Could you implement both?
// Definition for singly-linked list.
package leetcode

import (
	"strconv"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type LinkList struct {
	length int
	head   *ListNode
	tail   *ListNode
}

func NewLinkList(val int) *LinkList {
	node := &ListNode{val, nil}
	return &LinkList{
		length: 1,
		head:   node,
		tail:   node,
	}
}

func (this *LinkList) Append(val int) {
	node := &ListNode{val, nil}
	this.tail.Next, this.tail = node, node
	this.length++
}

func (this *LinkList) Str() string {
	str := ""
	node := this.head
	for node != nil {
		str += strconv.Itoa(node.Val)
		node = node.Next
	}
	return str
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		head.Next, prev, head = prev, head, head.Next
	}
	return prev
}
