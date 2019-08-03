package main

import "testing"

func TestMyQueue(t *testing.T) {
	queue := Constructor()
	queue.Push(1)
	queue.Push(2)
	queue.Push(3)
	if queue.Pop() != 1 {
		t.Error("232 implement queue using stask not work corrently.")
	}
	if queue.Peek() != 2 {
		t.Error("232 implement queue using stask not work corrently.")
	}
	if queue.Empty() {
		t.Error("232 implement queue using stask not work corrently.")
	}
}
