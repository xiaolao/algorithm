// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

// Example 1:

// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//  

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.

#include <sys/_types/_size_t.h>
#include <vector>

using std::vector;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n;
        int row[9][9] = {0};
        int col[9][9] = {0};
        int cel[9][9] = {0};

        for (size_t i=0; i<9; ++i) {
            for (size_t j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                n = board[i][j] - '1';

                if (row[i][n] == 0)
                    row[i][n] = 1;
                else
                    return false;

                if (col[j][n] == 0)
                    col[j][n] = 1;
                else
                    return false;

                if (cel[(i/3)*3+(j/3)][n] == 0)
                    cel[(i/3)*3+(j/3)][n] = 1;
                else
                    return false;
            }
        }
        return true;
    }
};
