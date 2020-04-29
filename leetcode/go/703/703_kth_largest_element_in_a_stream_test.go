package main

import (
	"container/heap"
	"fmt"
	"testing"
)

// func TestKthLargest(t *testing.T) {
// 	k := 3
// 	arr := []int{1, 8, 5, 4, 2}
// 	obj := Constructor(k, arr)
// 	fmt.Println(*obj.pq)
// fmt.Println(obj.Add(3))
// if obj.Add(3) != 4 {
// 	t.Error("701 Kth largest element in a stream not work corrently!")
// }
// if obj.Add(5) != 5 {
// 	t.Error("701 Kth largest element in a stream not work corrently!")
// }
// if obj.Add(10) != 5 {
// 	t.Error("701 Kth largest element in a stream not work corrently!")
// }
// if obj.Add(9) != 8 {
// 	t.Error("701 Kth largest element in a stream not work corrently!")
// }
// if obj.Add(4) != 8 {
// 	t.Error("701 Kth largest element in a stream not work corrently!")
// }
// }

func TestPriorityQueue(t *testing.T) {
	items := map[string]int{
		"banana": 3,
		"apple":  2,
		"pear":   4,
	}
	pq := make(PriorityQueue, len(items))

	i := 0
	for value, priority := range items {
		pq[i] = &Item{
			value:    value,
			priority: priority,
			index:    i,
		}
		i++
	}

	// pass the address of priority queue to head.Init
	heap.Init(&pq)

	item := &Item{
		value:    "orange",
		priority: 1,
	}
	heap.Push(&pq, item)
	pq.update(item, item.value, 5)

	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		fmt.Printf("%.2d:%s\n", item.priority, item.value)
	}
}
