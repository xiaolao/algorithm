# Say you have an array for which the ith element is the price of a given stock on day i.

# Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

# Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

# Example 1:

# Input: [7,1,5,3,6,4]
# Output: 7
# Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
#              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
# Example 2:

# Input: [1,2,3,4,5]
# Output: 4
# Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
#              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
#              engaging multiple transactions at the same time. You must sell before buying again.
# Example 3:

# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.

# 使用动态规划的思想远程
# 定义状态: DP[i][j]其中i为prices的下标，表示从0到i的最大收益，j表示是否拥有股票，有两个状态0表示没有股票，1表示拥有股票
# 状态转移方程: 
# DP[i][0] = max(DP[i-1][1] + prices[i], DP[i-1][0])
# DP[i][1] = max(DP[i-1][1], DP[i-1][0] - prices[i])

# [7, 1, 5, 3, 6, 4]
# DP[0][1] = -7 DP[0][0] = 0
# DP[1][0] = max(-7+1, 0) = 0 DP[1][1] = max(-7, -1) = -1
# DP[2][0] = max(-1+5, 0) = 4 DP[2][1] = max(-1, 0-5) = -1
# DP[3][0] = max(-1+3, 4) = 4 DP[3][1] = max(-1, 4 - 3) = 1
# DP[4][0] = max(1+6, 4)  = 7 DP[4][1] = max(1, 4-6) = 1
# DP[5][0] = max(1+4, 6)  = 7

from typing import List


class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1: return 0
        mp_0, mp_1 = 0, -prices[0]
        for i in range(1, len(prices)):
            mp_0 = max(mp_0, mp_1+prices[i])
            mp_1 = max(mp_0-prices[i], mp_1)
        return mp_0


if __name__ == "__main__":
    solution = Solution()
    A = [7, 1, 5, 3, 6, 4]
    assert solution.maxProfit(A) == 7
    B = [1, 2, 3, 4, 5]
    assert solution.maxProfit(B) == 4


