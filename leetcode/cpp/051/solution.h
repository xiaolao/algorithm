// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9
//
// 思路
// 分别用长度为n的整数col,dif,sum来记录不能放置的位置 
// ~ 位求反
// << 左移
// >> 右移
// & 位与
// ^ 位异或
// | 位或

#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;
using std::function;

class Solution {
public:
    // 回溯算法（深度优先搜索+剪枝）+ 位运算
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> queens(n, string(n, '.'));
        int sup = (1 << n) - 1;

        function<void(int, int, int)> dfs = [&](int row, int l, int r) {
            if (row == sup) { result.push_back(queens); return; }
            for (int cur = sup & (~(row|l|r)), pos = 0; cur;) {
                pos = cur & (-cur);
                cur -= pos;

                int i = __builtin_popcount(row);
                int j = __builtin_ctz(pos);
                queens[i][j] = 'Q';
                dfs(row+pos, (l+pos)<<1, (r+pos)>>1);
                queens[i][j] = '.';
            }
        };

        dfs(0, 0, 0);
        return result;
    }
};
