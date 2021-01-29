# The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

# Given an integer n, return all distinct solutions to the n-queens puzzle.

# Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 
# Example 1:

# Input: n = 4
# Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
# Example 2:

# Input: n = 1
# Output: [["Q"]]
 

# Constraints:

# 1 <= n <= 9

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        def dfs(queen: List[int], _sum: List[int], _dif: List[int]) -> None:
            i = len(queen)  # i为行下标
            if len(queen) == n:
                result.append(queen)
                return
            for j in range(n):  # j为列下标
                if j not in queen and i+j not in _sum and j-i not in _dif:
                    dfs(queen + [j], _sum + [i+j], _dif + [j-i])

        result: List[List[int]] = []
        dfs([], [], [])
        return [["."*i + "Q" + "."*(n-i-1) for i in solution] for solution in result]

