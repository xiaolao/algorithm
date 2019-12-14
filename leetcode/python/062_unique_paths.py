# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

# How many possible unique paths are there?

# Note: m and n will be at most 100.

# S 0 0 0
# 0 0 0 E

# Example 1:

# Input: m = 3, n = 2
# Output: 3
# Explanation:
# From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
# 1. Right -> Right -> Down
# 2. Right -> Down -> Right
# 3. Down -> Right -> Right
# Example 2:

# Input: m = 7, n = 3
# Output: 28

# 排列组合思路
# 从入口S要走m + n - 2步到达出口, 从m+n-2中随机的往下m-1步

# 动态规划的思路
# 20 10 4  1
# 10 6  3  1
# 4  3  2  1
# 1  1  1  E

import math
from typing import List


class Solution:

    # 排列组合
    def uniquePathsI(self, m: int, n: int) -> int:
        return int(math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1))

    # 动态规划
    def uniquePathsII(self, m: int, n: int) -> int:
        dp = [[1 if i*j == 0 else 0  for i in range(n)] for j in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]


if __name__ == "__main__":
    solution = Solution()
    assert solution.uniquePathsI(3, 2) == 3
    assert solution.uniquePathsII(3, 2) == 3
    assert solution.uniquePathsI(7, 3) == 28
    assert solution.uniquePathsII(7, 3) == 28
