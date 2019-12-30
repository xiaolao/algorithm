# Given an unsorted array of integers, find the length of longest increasing subsequence.

# Example:

# Input: [10,9,2,5,3,7,101,18]
# Output: 4 
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
# Note:

# There may be more than one LIS combination, it is only necessary for you to return the length.
# Your algorithm should run in O(n2) complexity.
# Follow up: Could you improve it to O(n log n) time complexity?

# 分析用动态规划的思路解决
# 状态定义DP[i]表示包含第i位置元素的最大上升子序列
# 状态转移方程: 
# DP[i] = max(DP[j]) + 1 其中 0<=j<i 且 DP[i]>DP[j]
# LIS = max(DP[i]) 0<=i<length

from typing import List


class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) <= 0: return 0
        DP = [1] + [0] * (len(nums) - 1)



if __name__ == "__main__":

