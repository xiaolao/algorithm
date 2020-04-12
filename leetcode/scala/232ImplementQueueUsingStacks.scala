import scala.collection.mutable.Stack


class MyQueue() {

    /** Initialize your data structure here. */
	val inputStack = Stack[Int]()
	val outputStack = Stack[Int]()

    /** Push element x to the back of queue. */
    def push(x: Int) {
	  inputStack.push(x)
    }

    /** Removes the element from in front of queue and returns that element. */
    def pop(): Int = {
       move() 
	   outputStack.pop
    }

    /** Get the front element. */
    def peek(): Int = {
	  move()
	  outputStack.top
    }

    /** Returns whether the queue is empty. */
    def empty(): Boolean = {
	  inputStack.isEmpty && outputStack.isEmpty
    }

	/** move all elements of input stack to output stack **/
	def move(): Unit = {
	  if (!outputStack.isEmpty) return
	  while (!inputStack.isEmpty) {
		outputStack.push(inputStack.pop())
	  }
	}

}

object Solution {

  def main(args: Array[String]): Unit = {
  	var obj = new MyQueue()
	obj.push(1)
	obj.push(2)
	assert(obj.peek() == 1)
	assert(obj.pop() == 1)
	assert(obj.empty() == false)
  }

}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
