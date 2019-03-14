package leetcode

import "testing"

func TestReverseLinkedList(t *testing.T) {
	ll := NewLinkList(1)
	ll.Append(2)
	ll.Append(3)
	ll.Append(4)
	ll.Append(5)
	t.Log(ll.Str())
}
