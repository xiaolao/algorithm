// Say you have an array prices for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//  

// Constraints:

// 1 <= prices.length <= 3 * 10 ^ 4
// 0 <= prices[i] <= 10 ^ 4


// 动态规划: 递归+记忆化
// 1. 递归+记忆化 --> 递推
// 2. 状态的定义：opt[n], dp[n], fib[n]
// 3. 状态转移方程：opt[n] = best_of(opt[n-1], opt[n-2], ...)
// 4. 最优子结构
// dp[i] = 

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    // 贪心算法
    int maxProfit(vector<int>& prices) {
        int profit = 0, size = prices.size();
        if (size < 2) return 0;
        for (int i = 1; i < size; ++i) {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }

    // 动态规划
};
