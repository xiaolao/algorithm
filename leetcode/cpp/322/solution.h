// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

//  

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
// Example 4:

// Input: coins = [1], amount = 1
// Output: 1
// Example 5:

// Input: coins = [1], amount = 2
// Output: 2
//  

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution {
public:

    // 动态规划法：与爬楼梯的题目类似, amount可以看成要上的台阶数
    // coins为一步可以走的台阶数，则可定义状态dp[i]为上到第i个台阶
    // 需要的最少的步数，因为按照coins里的走法，有些台阶不一定能走到，
    // 故初始化是可以将dp[i] = amount + 1, 最少步数不可能少于amount+1
    // dp[i] = min(dp[i-coins[j]])+1, 其中coins[j]<i;
    // 时间复杂度为 O(amount * N)
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0 || amount == 0) return 0;
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;
        for (size_t i = 1; i <= amount; i++) {
            for (size_t j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
