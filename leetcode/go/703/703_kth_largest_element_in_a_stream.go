package main

import (
	"container/heap"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type KthLargest struct {
	size int
	pq   *IntHeap
}

func Constructor(k int, nums []int) KthLargest {
	var pq IntHeap
	return KthLargest{
		size: k,
		pq:   &pq,
	}
}

func (this *KthLargest) Add(val int) int {
	if len(*this.pq) < this.size {
		heap.Push(this.pq, val)
		return -1
	}
	if (*this.pq)[this.size-1] < val {
		heap.Pop(this.pq)
		heap.Push(this.pq, val)
	}
	return (*this.pq)[this.size-1]
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
