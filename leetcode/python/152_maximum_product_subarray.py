# Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

# Example 1:

# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
# Example 2:

# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

# 动态规划问题
# 分析：由于数组中可能有负数，故状态要存max和min不止一个
# 1.定义状态：DP[i][0] DP[i][1] 为包含i个位置的最大,最小乘积子序
# 2.状态转移方程：
# DP[i][0] = max(DP[i-1][0]*nums[i], DP[i-1][1]*nums[i], nums[i])
# DP[i][1] = mix(DP[i-1][0]*nums[i], DP[i-1][1]*nums[i], nums[i])

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0
        # 循环交替使用[[0,0],[0,0]], 使得空间复杂度降为常数级别
        dp = [[0 for _ in range(2)] for _ in range(2)]
        dp[0][0], dp[0][1], max_product = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            x, y = i % 2, (i-1) % 2
            dp[x][0] = max(dp[y][0]*nums[i], dp[y][1]*nums[i], nums[i])
            dp[x][1] = min(dp[y][0]*nums[i], dp[y][1]*nums[i], nums[i])
            max_product = max(max_product, dp[x][0])
        return max_product


if __name__ == "__main__":
    solution = Solution()
    A = [2, 3, -2, 4]
    assert solution.maxProduct(A) == 6
    B = [-2, 0, -1]
    assert solution.maxProduct(B) == 0
    C = [2, 3, -2, 4, -1]
    assert solution.maxProduct(C) == 48

