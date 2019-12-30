# Say you have an array for which the i-th element is the price of a given stock on day i.

# Design an algorithm to find the maximum profit. You may complete at most k transactions.

# Note:
# You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

# Example 1:

# Input: [2,4,1], k = 2
# Output: 2
# Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
# Example 2:

# Input: [3,2,6,5,0,3], k = 2
# Output: 7
# Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
#              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

# 思路：使用动态规划的思想，确定正交的状态维度，i表示prices下标，j表示股票交易次数，k表示是否拥有股票
# 状态定义: MP[i][k][j] i->{0,...,len(prices)}; k->{0,...,K}, j->{0, 1}
# 状态转移方程: 
# MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k-1][1] + prices[i])
# MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k-1][0] - prices[i])

from typing import List

class Solution:

    def maxProfit(self, max_k: int, prices: List[int]) -> int:
        # MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k-1][1] + prices[i])
        # MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k-1][0] - prices[i])
        n = len(prices)
        if max_k > n / 2: 
            return self._maxProfit(prices)
        MP = [[[0 for _ in range(2)] for _ in range(max_k)] for _ in range(n)]
        for i in range(0, n):
            for k in range(1, max_k+1):
                if i == 0:
                    MP[i][k][0] = 0
                    MP[i][k][1] = -prices[i]
                MP[i][k][0] = max(MP[i-1][k][0], MP[i-1][k-1][1]+prices[i])
                MP[i][k][1] = max(MP[i-1][k][1], MP[i-1][k-1][0]-prices[i])

        return MP[n-1][max_k][0]

    def _maxProfit(self, prices: List[int]):
        # MP[i][0] = max(MP[i-1][0], MP[i-1][1]+prices[i])
        # MP[i][1] = max(MP[i-1][0]-prices[i], MP[i-1][1])
        if len(prices) < 1: return 0
        mp_0, mp_1 = 0, -prices[0]
        for i in range(1, len(prices)):
            mp_0 = max(mp_0, mp_1+prices[i])
            mp_1 = max(mp_0-prices[i], mp_1)
        return mp_0


if __name__ == "__main__":
    solution = Solution()
    A = [2, 4, 1]
    assert solution.maxProfit(2, A) == 2
    B = [3, 2, 6, 5, 0, 3] 
    assert solution.maxProfit(2, B) == 7

