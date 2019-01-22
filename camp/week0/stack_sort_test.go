package week0

import "testing"

func TestStackSort(t *testing.T) {
	r := NewArrayStack()
	r.Push(3)
	r.Push(4)
	r.Push(2)
	r.Push(1)
	StackSort(r)
	t.Log(r.Pop())
	t.Log(r.Pop())
	t.Log(r.Pop())
	t.Log(r.Pop())
}
