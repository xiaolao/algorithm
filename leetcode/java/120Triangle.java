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

// 定义状态：DP[i, j]表示自底向上到位置i, j的最小路径和
// 状态转移方程：DP[i, j] = min(DP[i+1, j], DP[i+1, j+1]) + triangle[i, j]


class Solution {

    public static void main(String[] args) throws Exception {
        int A[][] = {{2,}, {3,4}, {6,5,7}, {4,1,8,3}};
        assert minimumTotal(A) == 11;
    }

    public static int minimumTotal(int[][] triangle) {
        int[] mini = triangle[triangle.length-1];
        for (int i = triangle.length - 2; i >=0; i--) {
            for (int j = 0; j <= i; j++) { 
                mini[j] = Math.min(mini[j], mini[j+1]) + triangle[i][j];
            }
        }
        return mini[0];
    }
}
