// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

//  

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
//  

// Constraints:

// 1 <= n <= 9

#include <functional>

using std::function;


class Solution {
public:
    // 回溯+位运算
    int totalNQueens(int n) {
        int sup = (1 << n) - 1, sum = 0;
        function<void(int, int, int)> dfs = [&](int row, int l, int r) {
            if (row == sup) { ++sum; return; }  // 递归终止条件
            for (int cur = sup & (~(row|l|r)), pos = 1; cur; dfs(row+pos, (l+pos)<<1, (r+pos)>>1)) {
                pos = cur & (-cur);  // 获取cur从右边开始第一个1的位置
                cur -= pos;  // 在位置pos处放入皇后，并将位置标记为不可用
            }
        };
        dfs(0, 0, 0);
        return sum;
    }
};
