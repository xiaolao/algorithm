# Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

# Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

#  

# Example 1:

# Input: [6,0,8,2,1,5] 
# Output: 4
# Explanation: 
# The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
# Example 2:

# Input: [9,8,1,0,1,9,4,0,4,1]
# Output: 7
# Explanation: 
# The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
#  

# Note:

# 2 <= A.length <= 50000
# 0 <= A[i] <= 50000

# 分析: 对原数组排序，排序后得到原下标列表，计算得到后面的下标减去前面下标的最大值
# [6,0,8,2,1,5]
# [1, 4, 3, 5, 0, 3]
# [0, 3, 2, 4, 0, 2]
# max -> 4

from typing import List


class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        max_width = 0
        m = float("inf")
        for i in sorted(range(len(A)), key=A.__getitem__):
            max_width = max(max_width, i - m)
            m = min(m, i)
        return max_width
            

