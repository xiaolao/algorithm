// Given an m x n board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 200
// 1 <= word.length <= 103
// board and word consists only of lowercase and uppercase English letters.

#include <cstring>
#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::function;

class Solution {
public:
    // 深度优先搜索+回溯算法 时间复杂度上界为O(N*M*3^L)
    // N,M分别为矩阵board的行和列，L为word的长度。空间复杂度为O(min(L, N*M))
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size(), len = word.size();
        // 使用递归实现DFS，与N-皇后问题的解法类似
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            // 递归终止条件一，失败：坐标(i,j)超出board边界
            if (i >= row || i < 0 || j >= col || j < 0) return false;
            // 递归终止条件二，失败：位置board中(i,j)的字符不等于word中的
            if (board[i][j] != word[k]) return false;
            // 递归终止条件三，成功：找到单词
            if (k == len - 1) return true;

            // 记住已经使用的位置
            board[i][j] = ' ';
            // 在位置i,j附近搜索与第k+1个字符相等的位置
            if (dfs(i-1, j, k+1) ||
                dfs(i+1, j, k+1) ||
                dfs(i, j-1, k+1) ||
                dfs(i, j+1, k+1))
            return true;
           // 失败后回溯
           board[i][j] = word[k];
           return false;
        };

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
