# You are climbing a stair case. It takes n steps to reach to the top.

# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# Note: Given n will be a positive integer.

# Example 1:

# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps

# Example 2:

# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step

# 动态规划的思想
# s[1] = 1, s[2] = 2, s[3] = s2 + s1  ... s[n] = s[n-1] + s[n-2]

class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 0:
            return 0
        x, y = 1, 1
        for _ in range(1, n):
            x, y = y, x + y
        return y


if __name__ == "__main__":
    solution = Solution()
    assert solution.climbStairs(0) == 0
    assert solution.climbStairs(1) == 1
    assert solution.climbStairs(2) == 2
    assert solution.climbStairs(5) == 8
