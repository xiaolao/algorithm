from typing import List


class Solution(object):

    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 1 or k > len(nums):
            raise Exception("k is out of range.")
        k = len(nums)-k
        start, end = 0, len(nums) - 1
        position = self.partition(nums, start, end)
        while position != k:
            if position < k:
                start = position + 1
            else:
                end = position - 1
            position = self.partition(nums, start, end)
        return nums[k]

    def partition(self, nums: List[int], low: int, high: int) -> int:
        pivot = nums[low]
        while low < high:
            while low < high and nums[high] >= pivot:
                high -= 1
            nums[low] = nums[high]
            while low < high and nums[low] <= pivot:
                low += 1
            nums[high] = nums[low]
        nums[low] = pivot
        return low
