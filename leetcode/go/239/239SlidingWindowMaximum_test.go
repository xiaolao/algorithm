package main

import "testing"

func TestMaxSlidingWindow(t *testing.T) {
	nums := []int{}
	t.Log(maxSlidingWindow(nums, 3))

	// nums = []int{1, -1}
	// t.Log(maxSlidingWindow(nums, 1))

	nums = []int{7, 2, 4}
	t.Log(maxSlidingWindow(nums, 2))

	nums = []int{1, 3, -1, -3, 5, 3, 6, 7}
	t.Log(maxSlidingWindow(nums, 3))

	nums = []int{1, 3, -1, -3, 5, 3, 6, 7}
	t.Log(maxSlidingWindow(nums, 2))

}
