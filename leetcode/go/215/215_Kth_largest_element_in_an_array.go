// 题目：
// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.
// For example, Given [3,2,1,5,6,4] and k = 2, return 5.
// Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
// 思路：
// 借鉴快速排序的思想，可以在o(n)的时间复杂度，o(1)的空间复杂度内完成。
package leetcode

func FindKthLargest(nums []int, k int) int {
	k = len(nums) - k
	start, end := 0, len(nums)-1
	p := partition(nums, start, end)
	for p != k {
		if p < k {
			start = p + 1
		} else {
			end = p - 1
		}
		p = partition(nums, start, end)
	}
	return nums[k]
}

func partition(nums []int, start, end int) int {
	pivot := nums[end]
	for start < end {
		for start < end && nums[start] <= pivot {
			start++
		}
		nums[end] = nums[start]
		for start < end && nums[end] >= pivot {
			end--
		}
		nums[start] = nums[end]
	}
	nums[start] = pivot
	return start
}
