# Implement the following operations of a queue using stacks.

# push(x) -- Push element x to the back of queue.
# pop() -- Removes the element from in front of queue.
# peek() -- Get the front element.
# empty() -- Return whether the queue is empty.
# Example:

# MyQueue queue = new MyQueue();

# queue.push(1);
# queue.push(2);  
# queue.peek();  // returns 1
# queue.pop();   // returns 1
# queue.empty(); // returns false
# Notes:

# You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
# Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
# You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.inStack, self.outStack = [], []
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.inStack.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        self.move()
        return self.outStack.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        self.move()
        return self.outStack[-1]
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return (not self.inStack) and (not self.outStack)

    def move(self) -> None:
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


if __name__ == "__main__":
    queue = MyQueue()
    queue.push(1)
    queue.push(2)
    assert queue.peek() == 1
    assert queue.pop() == 1
    assert queue.empty() is False
