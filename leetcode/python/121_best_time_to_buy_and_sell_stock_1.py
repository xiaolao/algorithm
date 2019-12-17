# Say you have an array for which the ith element is the price of a given stock on day i.

# If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

# Note that you cannot sell a stock before you buy one.

# Example 1:

# Input: [7,1,5,3,6,4]
# Output: 1, 4, 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
#              Not 7-1 = 6, as selling price needs to be larger than buying price.

# 分析
# DP[0] = 0
# DP[1] = 0  max(1-7+0, 0) start = 0, end = 0, temp = 0, prices[1] - prices[0] = -6
# DP[2] = 4  max(5-1+0, 0) start = 1, end = 2, temp = 0, prices[2] - prices[1] = 4
# DP[3] = 2  max(3-5+4, 0) start = 1, end = 3, temp = 4, prices[3] - prices[2] = -2
# DP[4] = 5  max(6-3+2, 0) start = 1, end = 4, temp = 2, prices[4] - prices[3] = 3

# [7,2,5,1,6,4]


# 动态规划的问题
# 定义状态: DP[i]在i时刻卖出最大的股票收益
# 状态转移方程：DP[i] = max(0, DP[i-1] + prices[i] - prices[i-1])


from typing import List

class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1: return 0
        temp = max_profit = 0
        for i in range(1, len(prices)):
            temp = max(0, prices[i]-prices[i-1]+temp)
            max_profit = max(temp, max_profit)
        return max_profit

    def maxProfitAndIndex(self, prices: List[int]) -> (int, int, int):
        if len(prices) <= 1: return 0
        mini = prices[0]
        temp = max_profit = start = end = 0
        for i in range(1, len(prices)):
            temp = max(0, prices[i]-prices[i-1]+temp)
            if max_profit < temp:
                max_profit = temp
                end = i
            if prices[i] < mini:
                start = i
                mini = prices[i]

        return start, end, max_profit


if __name__ == "__main__":
    solution = Solution()
    A = [7, 1, 5, 3, 6, 4]
    assert solution.maxProfit(A) == 5
    B = [7, 2, 5, 1, 6, 4]
    print(solution.maxProfitAndIndex(B))
    assert solution.maxProfitAndIndex(B) == (3, 4, 5)

