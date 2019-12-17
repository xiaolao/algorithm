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
# 状态定义: MP[i][j][k] i->{0,...,len(prices)}; k->{0,...,K}


from typing import List

class Solution:

    def maxProfit(self, k: int, prices: List[int]) -> int:



if __name__ == "__main__":

