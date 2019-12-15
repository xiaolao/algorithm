// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:

// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
package main

// 状态的定义 DP[i, j]表从下至上第i，j个位置的最小路径和
// 状态转移方程 DP[i, j] = min(DP[i+1, j], DP[i+1, j+1]) + triangle[i, j]

func minimumTotal(triangle [][]int) int {
	var m int
	mini := make([]int, len(triangle))
	copy(mini, triangle[len(triangle)-1])
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j < i+1; j++ {
			if mini[j] > mini[j+1] {
				m = mini[j+1]
			} else {
				m = mini[j]
			}
			mini[j] = m + triangle[i][j]
		}
	}
	return mini[0]
}
