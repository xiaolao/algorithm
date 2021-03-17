// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

// Constraints:

// 0 <= k <= 100
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
#include <vector>
#include <algorithm>

using std::min;
using std::max;
using std::vector;

class Solution {
public:

    // 对于每天结束后,都有两种状态持有股票和不持有股票，分别用 buy和sell表示
    // 持有股票的状态定义：buy[i][j]表示第i天结束后恰好进行了j次交易且持有股票时的最大收益
    // 不持有股票的状态定义为：sell[i][j]表示第i天结束后恰好进行了j次交易且手上不持有股票的最大收益
    // buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i]);
    // sell[i][j] = max(sell[i-1][j], buy[i-1][j-1]+prices[i]);
    // 由上面的动态转移方程可知每次遍历只需要查找buy[i-1]和sell[i-1]，故只需要用一维数组保存状态, 
    // buy[j], sell[j] 分别表示i-1天结束后恰好交易j次手上持有股票和不持有股票时的最大收益。
    // buy[j] = max(buy[j], sell[j]-prices[i])
    // sell[j] = max(sell[j], buy[j-1]+prices[i])
    // 考虑边界条件 buy[0] = -prices[0], sell[0] = 0;
    // n天最多进行n/2向下取整次交易，所以大于n/2的部分交易时没有意义的
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 1 || k <= 0) return 0;

        vector<int> buy(k+1);
        vector<int> sell(k+1);

        k = min(k, n / 2);

        // 对i-1为0时做特殊处理
        buy[0] = -prices[0], sell[0] = 0;
        for (size_t j = 1; j <= k; j++) {
            buy[j] = sell[j] = INT_MIN / 2;
        }

        for (size_t i = 0; i < n; i++) {
            buy[0] = max(buy[0], sell[0]-prices[i]);
            for (size_t j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j]-prices[i]);
                sell[j] = max(sell[j], buy[j-1]+prices[i]);
            }
        }

        return *std::max_element(sell.begin(), sell.end());
    }
};
