# Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

# Follow up:
# Could you solve it in linear time?

# Example:

# Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
# Output: [3,3,5,5,6,7] 
# Explanation: 

# Window position                Max
# ---------------               -----
# [1  3  -1] -3  5  3  6  7       3
#  1 [3  -1  -3] 5  3  6  7       3
#  1  3 [-1  -3  5] 3  6  7       5
#  1  3  -1 [-3  5  3] 6  7       5
#  1  3  -1  -3 [5  3  6] 7       6
#  1  3  -1  -3  5 [3  6  7]      7

from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return []
        window, result = [], []
        for index, value in enumerate(nums):
            if index >= k and window[0] <= index - k:
                window.pop(0)
            while window and nums[window[-1]] <= value:
                window.pop()
            window.append(index)
            if index >= k-1:
                result.append(nums[window[0]])
        return result


if __name__ == '__main__':
    solution = Solution()
    input_stream = [1, 3, -1, -3, 5, 3, 6, 7]
    assert solution.maxSlidingWindow(input_stream, 3) == [3, 3, 5, 5, 6, 7]
