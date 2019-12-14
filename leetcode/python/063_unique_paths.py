# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

# Now consider if some obstacles are added to the grids. How many unique paths would there be?

# An obstacle and empty space is marked as 1 and 0 respectively in the grid.

# Note: m and n will be at most 100.

# Example 1:

# Input:
# [
#   [0,0,0],
#   [0,1,0],
#   [0,0,0]
# ]
# Output: 2
# Explanation:
# There is one obstacle in the middle of the 3x3 grid above.
# There are two ways to reach the bottom-right corner:
# 1. Right -> Right -> Down -> Down
# 2. Down -> Down -> Right -> Right

from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if len(obstacleGrid) <= 0 or len(obstacleGrid[0]) <= 0:
            return 0
        # 若入口处有障碍则无法通行
        if obstacleGrid[0][0] == 1:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        # 初始化第一列
        obstacleGrid[0][0] = 1
        for i in range(1, m):
            obstacleGrid[i][0] = int(obstacleGrid[i][0] == 0 and obstacleGrid[i-1][0] == 1)
        # 初始化第一行
        for j in range(1, n):
            obstacleGrid[0][j] = int(obstacleGrid[0][j] == 0 and obstacleGrid[0][j-1] == 1)

        # 根据递推公式推导
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j] = 0

        return obstacleGrid[-1][-1]


if __name__ == "__main__":
    solution = Solution()
    A = [
        [0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]
    ]
    assert solution.uniquePathsWithObstacles(A) == 2
    B = [
        [0, 0, 1, 0],
        [0, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 0]
    ]
    assert solution.uniquePathsWithObstacles(B) == 7
    D = [[0,1,0,0,1,0]]
    assert solution.uniquePathsWithObstacles(D) == 0
    E = [[0,],[0,],[1,],[0,]]
    assert solution.uniquePathsWithObstacles(E) == 0

