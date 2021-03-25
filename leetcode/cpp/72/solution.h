// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include <algorithm>
#include <cstddef>
#include <string>

using std::min;
using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t n = word1.size();
        size_t m = word2.size();
        if (n*m==0) return n+m;

        int dp[n+1][m+1];
        for (size_t i = 0; i <= n; i++) dp[i][0] = i;
        for (size_t j = 0; j <= m; j++) dp[0][j] = j;

        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 1; j <= m; j++) {
                int del_op = dp[i-1][j] + 1;
                int ins_op = dp[i][j-1] + 1;
                int rep_op = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) rep_op += 1;
                dp[i][j] = min(rep_op, min(del_op, ins_op));
            }
        }
        return dp[n][m];
    }
};
