// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

package leetcode

func twoSum(nums []int, target int) []int {
	tmpMap := make(map[int]int)
	for i, num := range nums {
		_, ok := tmpMap[num]
		if ok {
			return []int{tmpMap[num], i}
		} else {
			tmpMap[target-num] = i
		}
	}
	return nil
}
