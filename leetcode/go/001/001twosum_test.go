package leetcode

import "testing"

func TesttwoSum(t *testing.T) {
	nums := []int{2, 7, 11, 15}
	result := twoSum(nums, 9)
	if result[0] != 0 || result[1] == 1 {
		t.Error("TwoSum doesn't work correctly!")
	}
	result = twoSum(nums, 14)
	if result != nil {
		t.Error("TwoSum doesn't work correctly!")
	}
}
