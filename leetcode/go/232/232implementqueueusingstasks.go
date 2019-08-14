// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Example:

// MyQueue queue = new MyQueue();

// queue.push(1);
// queue.push(2);
// queue.peek();  // returns 1
// queue.pop();   // returns 1
// queue.empty(); // returns false
// Notes:

// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

package main

type Stack struct {
	top  int
	data []int
}

func NewStack() *Stack {
	return &Stack{
		top:  -1,
		data: make([]int, 0, 32),
	}
}

func (s *Stack) IsEmpty() bool {
	if s.top < 0 {
		return true
	}
	return false
}

func (s *Stack) Push(v int) {
	s.top++
	if s.top > len(s.data)-1 {
		s.data = append(s.data, v)
	} else {
		s.data[s.top] = v
	}
}

func (s *Stack) Pop() int {
	if s.IsEmpty() {
		panic("stack is empty!")
	}
	v := s.data[s.top]
	s.top--
	return v
}

func (s *Stack) Peek() int {
	if s.IsEmpty() {
		panic("stack is empty!")
	}
	return s.data[s.top]
}

type MyQueue struct {
	inStack  *Stack
	outStack *Stack
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		inStack:  NewStack(),
		outStack: NewStack(),
	}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.inStack.Push(x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	this.Move()
	return this.outStack.Pop()
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	this.Move()
	return this.outStack.Peek()
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.inStack.IsEmpty() && this.outStack.IsEmpty()
}

func (this *MyQueue) Move() {
	if !this.outStack.IsEmpty() {
		return
	}
	for !this.inStack.IsEmpty() {
		this.outStack.Push(this.inStack.Pop())
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
