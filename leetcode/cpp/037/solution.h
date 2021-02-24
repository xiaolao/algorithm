// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

//  

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

#include <bitset>
#include <vector>

using std::bitset;
using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<bitset<9>>(9, bitset<9>());
        col = vector<bitset<9>>(9, bitset<9>());
        cel = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt= 0;  // 用于记录需要填的空格数
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt += (board[i][j] == '.');  // 当为代填空格时，累加cnt
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                // 给bitset在有数值的位置进行标记
                row[i] |= (1 << n);  // 按位或赋值
                col[j] |= (1 << n);
                cel[i/3][j/3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

    bool dfs(vector<vector<char>>& board, int cnt) {
        // 递归终止条件
        if (cnt <= 0) return true;

        vector<int> pos = getNext(board);
        bitset<9> ret = getPossibleStatus(pos[0], pos[1]);
        for (int n = 0; n < ret.size(); n++) {
            if (!ret.test(n)) continue;
            fillNum(pos[0], pos[1], n, true);
            board[pos[0]][pos[1]] = n + '1';
            if (dfs(board, cnt-1)) return true;
            board[pos[0]][pos[1]] = '.';
            fillNum(pos[0], pos[1], n, false);
        }
        return false;
    }

    // 通过对row,col,cel做位运算，找出能填数字最少的空格位置
    vector<int> getNext(vector<vector<char>>& board) {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                bitset<9> cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = {i ,j};
                minCnt = cur.count();
            }
        }
        return ret;
    }

    // 找出位置i，j可以填的可能数字
    bitset<9> getPossibleStatus(int i, int j) {
        return ~(row[i] | col[j] | cel[i/3][j/3]);
    }

    void fillNum(int i, int j, int n, bool fillFlag) {
        bitset<9> pick(1 << n);
        row[i] = (fillFlag) ? (row[i] | pick) : (row[i] ^ pick);
        col[j] = (fillFlag) ? (col[j] | pick) : (col[j] ^ pick);
        cel[i/3][j/3] = (fillFlag) ? (cel[i/3][j/3] | pick) : (cel[i/3][j/3] ^ pick);
    }


private:
    vector<bitset<9>> row;
    vector<bitset<9>> col;
    vector<vector<bitset<9>>> cel;
};
