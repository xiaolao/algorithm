package leetcode

import "testing"

func TestFindKthLargest(t *testing.T) {
	nums := []int{9, 5, 6, 2, 3, 4, 1, 7, 8, 0}
	t.Log(FindKthLargest(nums, 1))  // return 9
	t.Log(FindKthLargest(nums, 2))  // return 8
	t.Log(FindKthLargest(nums, 10)) // return 0
}
