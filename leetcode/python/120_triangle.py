# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

# For example, given the following triangle

# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

# Note:

# Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

# 动态规划问题，倒着走，可以定义状态
# 1.定义转态： DP[i, j] 为三角形从底部到i，j位置的最小路径和
# 2.得出递推方程：DP[i, j] = min(DP[i+1, j], DP[i+1, j+1]) + Triangle[i, j]

from typing import List
from copy import deepcopy


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        mini = deepcopy(triangle[-1])
        for i in range(len(triangle)-2, -1, -1):
            for j in range(0, i+1):
                mini[j] = min(mini[j], mini[j+1]) + triangle[i][j]
        return mini[0]


if __name__ == "__main__":
    A = [
        [2],
        [3,4],
        [6,5,7],
        [4,1,8,3]
    ]

    solution = Solution()
    assert solution.minimumTotal(A) == 11

